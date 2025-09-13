#include "first.h"

#include "main.h"
#include "string_functions.h"

#include <stdio.h>

void f_read_onegin(char f_onegin[][LEN_OF_LINE]) {
    FILE *text = fopen("Onegin.txt", "r");

    int cnt_strok = 0;
    for (; fgets(f_onegin[cnt_strok], LEN_OF_LINE, text); ++cnt_strok) {
    }

    fclose(text);
}

void f_strswap(char f_onegin[][LEN_OF_LINE], int strok1, int strok2) {

    char temp [LEN_OF_LINE] = {};
    my_strcpy(temp, f_onegin[strok1]);
    my_strcpy(f_onegin[strok1], f_onegin[strok2]);
    my_strcpy(f_onegin[strok2], temp);
}

void f_buble_sort(int cnt_strok, char f_onegin[][LEN_OF_LINE]) {
    for (int i = 0; i < cnt_strok - 1; ++i) {
        for (int j = 0; j < cnt_strok - i - 1; ++j) {

            if (my_strcmp(f_onegin[j], f_onegin[j + 1]) > 0) {
                f_strswap(f_onegin, j, j + 1);
            }
        }
    }
}

void f_puts_onegin(int cnt_strok, char f_onegin[][LEN_OF_LINE]) {
    FILE *text_sort = fopen("Onegin_sort.txt", "w");

    for (int i = 0; i < cnt_strok; ++i) {
        fputs(f_onegin[i], text_sort);
    }

    fclose(text_sort);
}