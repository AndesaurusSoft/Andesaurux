#include "unistd.h"
#include "time.h"
int sleep(time_t seconds) {
    clock_t end_time = clock() + seconds * CLOCKS_PER_SEC;

    while (clock() < end_time) {
        // Do nothing, just wait
    }
}
