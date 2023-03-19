#pragma once

#include <mach/mach_types.h>

#include <stdint.h>
#include <time.h>

struct mach_timebase_info {
	uint32_t numer;
	uint32_t denom;
};

typedef struct mach_timebase_info *mach_timebase_info_t;

inline
kern_return_t mach_timebase_info(mach_timebase_info_t info)
{
	info->numer = 1000;
	info->denom = 1;
	return 0;
}


inline uint64_t
mach_absolute_time(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}
