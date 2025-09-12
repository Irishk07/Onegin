#ifndef FIRST_H_
#define FIRST_H_

const int LEN_OF_FILE = 8500;
const int LEN_OF_LINE = 200;

void strswap(char onegin[][LEN_OF_LINE], int strok1, int strok2);

void buble_sort(int cnt_strok, char onegin[][LEN_OF_LINE]);

void read_onegin(char onegin[][LEN_OF_LINE]);

void puts_onegin(int cnt_strok, char onegin[][LEN_OF_LINE]);

#endif //FIRST_H