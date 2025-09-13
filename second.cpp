#include "second.h"

#include "main.h"
#include "string_functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void s_read_onegin(const char *s_onegin[]) {
    FILE *text = fopen("Onegin.txt", "r");

    char temp[LEN_OF_LINE] = {};
    for (int i = 0; my_fgets(temp, LEN_OF_LINE, text); ++i) {
        s_onegin[i] = my_strdup(temp);
    }

    fclose(text);
}

void s_strswap(const char *s_onegin[], size_t strok1, size_t strok2) {
    const char *temp = s_onegin[strok1];
    s_onegin[strok1] = s_onegin[strok2];
    s_onegin[strok2] = temp;
}

void s_buble_sort(const char *s_onegin[]) {

    //как посчитать рамзер массива с указателями //TODO

    for (size_t i = 0; i < LEN_OF_FILE; ++i) {
        for (size_t j = 0; j < LEN_OF_FILE - i - 1; ++j) {
            if (s_onegin[j] == NULL || s_onegin[j + 1] == NULL) { //FIXME
                continue;
            }
            
            if (my_strcmp(s_onegin[j], s_onegin[j + 1]) > 0) {
                s_strswap(s_onegin, j, j + 1);
            }
        }
    }
}

void s_puts_onegin(const char *s_onegin[]) {
    FILE *text_sort = fopen("Onegin_sort.txt", "w");

    for (int i = 0; i < LEN_OF_FILE; ++i) {
        if (s_onegin[i] == NULL) { //FIXME
            continue;
        }
        fprintf(text_sort, "%s\n", s_onegin[i]);
    }

    fclose(text_sort);
}

void s_onegin_dtor(const char *s_onegin[]) {
    for (int i = 0; i < LEN_OF_FILE; ++i) {
        free((char *)s_onegin[i]); //FIXME
    }
}