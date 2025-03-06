#include <internal/syscall.h>
#include <time.h>
#include <errno.h>

int nanosleep(struct timespec *requested_time, struct timespec *remaining_time) {
    int ret = syscall(__NR_nanosleep, requested_time, remaining_time);

        if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}
