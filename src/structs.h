#ifndef __SOLOS_STRUCTS_H_
#define __SOLOS_STRUCTS_H_

#include "common.h"

typedef struct {
	struct { v3f pos, vel; } lin;
	struct { v3f pos, vel; } ang;
} phys_t;

#define SLS_BODY_BUF_LEN 2

typedef struct {
	phys_t buffer[SLS_BODY_BUF_LEN];
	float  mass;
	uuid_t id;
} body_t;


typedef struct {
	struct {
		body_t* set;
		size_t  count;
	} bodies;

} universe_t;

typedef struct {
	struct {
		int16_t base_port;
	} net;

	universe_t uni;

} state_t;

#endif
