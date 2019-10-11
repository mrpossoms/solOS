#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

#include "net.h"
#include "structs.h"

static int bind_sockets(int tcp, int udp, uint16_t base_port)
{
	int socks[2] = { tcp, udp };
	int protos[2] = { SOCK_STREAM, SOCK_DGRAM };

	for (int i = 0; i < 2; i++)
	{
		uint16_t port = base_port + i;
	
		struct addrinfo *result, *rp;
		struct addrinfo hints = {
			.ai_family = AF_INET,
			.ai_socktype = protos[i],
			.ai_flags = AI_PASSIVE,
		};

		int res = getaddrinfo(NULL, "0.0.0.0", &hints, &result);

		if (res)
		{
			fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(res));
			goto setup_sock_fail;
		}

		for (struct addrinfo* rp = result; rp; rp = rp->ai_next)
		{
			if(bind(socks[i], rp->ai_addr, rp->ai_addrlen) == 0) { break; }
		}
	}	

	return 0;

setup_sock_fail:
	return -1;
}

void* sls_network_loop(void* params)
{
	state_t* state = (state_t*)params;

	// here we create two sockets, one for reliable communication
	// such as player connection events, messages and data that
	// MUST be exchanged successfully, and a second for streaming
	// game state updates. Such as world dynamics
	int udp_sock = socket(AF_INET, SOCK_DGRAM, 0);
	int tcp_sock = socket(AF_INET, SOCK_STREAM, 0);    

	if (udp_sock < 0 || tcp_sock < 0)
	{
		// TODO: log failures here
		goto net_fail;
	}

	int res = bind_sockets(udp_sock, tcp_sock, state->net.base_port);
	if (res)
	{
		goto net_fail;
	}

net_fail:
	// TODO log failure
net_done:
	return NULL;
}
