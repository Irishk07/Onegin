#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>

#define FAIL goto exits

enum status {
    SUCCESS      = 0,
    FAILED       = 1,
    FAILED_DONE  = 2,
};

struct info_about_strings{
    char * point = NULL;
    int size = 0;
};

#endif //MAIN_H_