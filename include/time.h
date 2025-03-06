/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef	__TIME_H__
#define	__TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif
#include <internal/types.h>

struct timespec {
	long tv_sec;
	long tv_nsec;
};

int nanosleep(struct timespec *requested_time, struct timespec *remaining_time);

unsigned int sleep(unsigned int seconds);

#ifdef __cplusplus
}
#endif

#endif
