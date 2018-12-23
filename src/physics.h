#ifndef __SOLOS_PHYSICS_H_
#define __SOLOS_PHYSICS_H_

#include "structs.h"

static inline v3f sls_gravitation_force(body_t* b0, body_t* b1, int buf_idx)
{
	v3f delta = b0->buffer[buf_idx].lin.pos - b1->buffer[buf_idx].lin.pos;
	v3f delta2 = delta * delta;

	// f = G * m1 * m2 / r2
	// 1 / f = r2 / G * m1 * m2 
	return 1.f / (delta2 / (SOLOS_G * b0->mass * b1->mass));
}


static inline void sls_apply_force(body_t* b, v3f force, int buf_idx)
{
	b0->buffer[buf_idx].lin.vel += (force / b->mass);
}


static inline void sls_tlerp(body_t* b, float dt, int buf_idx)
{
	int t   = buf_idx % SLS_BODY_BUF_LEN;
	int t_1 = (buf_idx + 1) % SLS_BODY_BUF_LEN; 

	b0->buffer[t] = b0->buffer[t].lin.pos + b0->buffer[t].lin.vel * dt;
	b0->
}


#endif
