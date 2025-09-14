#ifndef THIRD_H_
#define THIRD_H_

#include <stdio.h>

char *t_read_onegin(int *cnt_strok, int *text_size);

void t_fill_array_onegin(const char **t_points_onegin, char *t_text_onegin, int text_size);

void t_strswap(const char **t_points_onegin, int strok1, int strok2);

void t_buble_sort(const char **t_points_onegin, int cnt_strok);

void t_puts_onegin(const char **t_points_onegin, int cnt_strok);

void t_onegin_dtor(char *t_text_onegin, const char **t_points_onegin);

#endif //THIRD_H_