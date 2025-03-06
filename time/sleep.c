#include <internal/syscall.h>
#include <time.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec requested_time;
    requested_time.tv_sec = seconds;
    requested_time.tv_nsec = 0;

    struct timespec remaining_time;

    int ret = nanosleep(&requested_time, &remaining_time);
    if (ret != 0)
        return -1;

    return requested_time.tv_sec;
}
