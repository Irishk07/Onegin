#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>


#define FAIL goto exits

enum status {
    SUCCESS      = 0,
    OPEN_ERROR   = 1,
    STAT_ERROR   = 2,
    CALLOC_ERROR = 3,
    READ_ERROR   = 4,
    CLOSE_ERROR  = 5,

};

#endif //MAIN_H_