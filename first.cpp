#include "first.h"

#include "string_functions.h"

#include <stdio.h>

void strswap(char onegin[][LEN_OF_LINE], int strok1, int strok2) {

    char temp [LEN_OF_LINE] = {};
    my_strcpy(temp, onegin[strok1]);
    my_strcpy(onegin[strok1], onegin[strok2]);
    my_strcpy(onegin[strok2], temp);
}

void buble_sort(int cnt_strok, char onegin[][LEN_OF_LINE]) {
    for (int i = 0; i < cnt_strok - 1; ++i) {
        for (int j = 0; j < cnt_strok - i - 1; ++j) {

            if (my_strcmp(onegin[j], onegin[j + 1]) > 0) {
                strswap(onegin, j, j + 1);
            }
        }
    }
}

void read_onegin(char onegin[][LEN_OF_LINE]) {
    FILE *text = fopen("Onegin.txt", "r");

    int cnt_strok = 0;
    for (; fgets(onegin[cnt_strok], LEN_OF_LINE, text); ++cnt_strok) {
    }

    fclose(text);
}

void puts_onegin(int cnt_strok, char onegin[][LEN_OF_LINE]) {
    FILE *text_sort = fopen("Onegin_sort.txt", "w");

    for (int i = 0; i < cnt_strok; ++i) {
        fputs(onegin[i], text_sort);
    }

    fclose(text_sort);
}