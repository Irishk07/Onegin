#ifndef FIRST_H_
#define FIRST_H_

const int LEN_OF_FILE = 8500;
const int LEN_OF_LINE = 200;

enum status {
    SUCCESS               = 0,
    READ_ERROR            = 1,
    STRDUP_ERROR          = 2,
    CLOSE_ERROR           = 3
};

status f_read_onegin(char f_onegin[][LEN_OF_LINE]);

void f_strswap(char f_onegin[][LEN_OF_LINE], int strok1, int strok2);

void f_buble_sort(int cnt_strok, char f_onegin[][LEN_OF_LINE]);

status f_puts_onegin(int cnt_strok, char f_onegin[][LEN_OF_LINE]);

#endif //FIRST_H