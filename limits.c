#include <stdio.h>
#include <sys/resource.h>

int main(void) {
    struct rlimit limit;

    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("Soft limit: %lld\n", (long long)limit.rlim_cur);
        printf("Hard limit: %lld\n", (long long)limit.rlim_max);
    } else {
        perror("getrlimit");
    }

    return 0;
}