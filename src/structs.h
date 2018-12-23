#ifndef __SOLOS_STRUCTS_H_
#define __SOLOS_STRUCTS_H_

#include "common.h"

typedef struct {
	struct { v3f pos, vel } lin;
	struct { v3f pos, vel } ang;
} phys_t;

#define SLS_BODY_BUF_LEN 2

typedef struct {
	phys_t buffer[SLS_BODY_BUF_LEN];
	float  mass;
	uuid_t id;
} body_t;


#endif
