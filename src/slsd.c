#include <cfg.h>

#include "constants.h"
#include "structs.h"
#include "physics.h"

struct {
	int running;
} flags = {
	1,
};

universe_t uni;

int main (int argc, char* argv[])
{
	cfg_base("/etc/solOS");

	// setup universe
	uni.bodies.count = 1 << 16;
	body_t system[uni.bodies.count];
	uni.bodies.set = system;

	for (unsigned int t = 0; flags.running; ++t)
	{
		sls_simulate(&uni, t % 2);
	}	

	return 0;
}
