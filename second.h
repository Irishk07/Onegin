#ifndef SECOND_H_
#define SECOND_H_

#include <stdio.h>

const int LEN_OF_FILE = 8500;
const int LEN_OF_LINE = 200;

enum status {
    SUCCESS               = 0,
    READ_ERROR            = 1,
    STRDUP_ERROR          = 2,
    CLOSE_ERROR           = 3
};

status s_read_onegin(char *s_onegin[]);

void s_strswap(char *s_onegin[], size_t strok1, size_t strok2);

void s_buble_sort(char *s_onegin[]);

status s_puts_onegin(char *s_onegin[]);

void s_onegin_dtor(char *s_onegin[]);

#endif //SECOND_H_