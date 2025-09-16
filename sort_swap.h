#ifndef SORT_SWAP_H_
#define SORT_SWAP_H_

#include "main.h"

void strswap(info_about_strings *onegin_strings, int strok1, int strok2);

void begin_skip_no_alpha(const char **pointer);

int begin_comparator(const void * param1, const void * param2);

void buble_sort_begin(info_about_strings *onegin_strings, int cnt_strok);

void skip_no_alpha_end(char **now_pointer, char *begin_pointer);

int end_comparator(const void * param1, const void * param2);

int point_comparator(const void * param1, const void * param2);

#endif //SORT_SWAP_H_