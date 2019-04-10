#ifndef __SOLOS_PHYSICS_H_
#define __SOLOS_PHYSICS_H_
#include "constants.h"
#include "structs.h"

static inline v3f sls_gravitation_force(body_t* b0, body_t* b1, int now_idx)
{
	v3f delta = b0->buffer[now_idx].lin.pos - b1->buffer[now_idx].lin.pos;
	v3f delta2 = delta * delta;

	// f = G * m1 * m2 / r2
	// 1 / f = r2 / G * m1 * m2 
	return 1.f / (delta2 / (SOLOS_G * b0->mass * b1->mass));
}


static inline void sls_apply_force(body_t* b, v3f force, int next_idx)
{
	b->buffer[next_idx].lin.vel += (force / b->mass);
}


static inline void sls_tlerp(body_t* b, float dt, int buf_idx)
{
	int t   = buf_idx % SLS_BODY_BUF_LEN;
	int t_1 = (buf_idx + 1) % SLS_BODY_BUF_LEN; 

	// TODO: compute expected location for next update time
	//b0->buffer[t].lin.pos = b0->buffer[t].lin.pos + b0->buffer[t].lin.vel * dt;
	//b0->buffer[t]
}

static inline void sls_nbody(
	body_t* body,
	body_t* bodies,
	size_t  body_count,
	float   dt,
	int     now_idx)
{
	int t   = now_idx % SLS_BODY_BUF_LEN;       // now
	int t_1 = (now_idx + 1) % SLS_BODY_BUF_LEN; // next

	for (int i = body_count; i--;)
	{
		// skip myself
		if (body == bodies + i) { continue; }

		v3f force = sls_gravitation_force(body, bodies + i, t);
		sls_apply_force(body, force, t_1);
		

	}
}

static inline void sls_simulate(universe_t* uni, int now_idx)
{
	for (int i = uni->bodies.count; i--;)
	{
		body_t* body = uni->bodies.set + i;
		sls_nbody(body, uni->bodies.set, uni->bodies.count, 0.1f, now_idx);
	}
}

#endif
