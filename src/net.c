#include <sys/socket.h>
#include <netdb.h>

#include "net.h"
#include "structs.h"

static int setup_sockets(int udp, int tcp)
{

	return 0;
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

	int res = setup_sockets(udp_sock, tcp_sock);
	if (res)
	{
		goto net_fail;
	}

net_fail:
	// TODO log failure
net_done:
	return NULL;
}
