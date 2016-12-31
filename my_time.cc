//
// Created by Sanhu Li on 12/10/16.
//

#include "my_time.h"

#include <sys/time.h>

double get_wall_time() {
    timeval time;
    gettimeofday(&time, nullptr);
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}