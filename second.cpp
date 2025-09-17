#include "second.h"

#include "main.h"
#include "string_functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

status s_read_onegin(char *s_onegin[]) {
    FILE *text = fopen("Onegin.txt", "r");
    if (text == NULL) {
        perror("Error is");

        return READ_ERROR;
    }

    char temp[LEN_OF_LINE] = {};
    for (int i = 0; my_fgets(temp, LEN_OF_LINE, text); ++i) {
        s_onegin[i] = my_strdup(temp);
        
        if (s_onegin[i] == NULL) {
            perror("Error is");

            s_onegin_dtor(s_onegin);

            return STRDUP_ERROR;
        }
    }

    fclose(text);
    if (text == NULL) {
        perror("Error is");

        s_onegin_dtor(s_onegin);

        return CLOSE_ERROR;
    }

    return SUCCESS;
}

void s_strswap(char *s_onegin[], size_t strok1, size_t strok2) {
    char *temp = s_onegin[strok1];
    s_onegin[strok1] = s_onegin[strok2];
    s_onegin[strok2] = temp;
}

void s_buble_sort(char *s_onegin[]) {

    //как посчитать размер массива с указателями //TODO

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

status s_puts_onegin(char *s_onegin[]) {
    FILE *text_sort = fopen("Onegin_sort.txt", "w");
    if (text_sort == NULL) {
        perror("Error is");

        s_onegin_dtor(s_onegin);

        return READ_ERROR;
    }

    for (int i = 0; i < LEN_OF_FILE; ++i) {
        if (s_onegin[i] == NULL) { //FIXME
            continue;
        }
        fprintf(text_sort, "%s\n", s_onegin[i]);
    }

    fclose(text_sort);
    if (text_sort == NULL) {
        perror("Error is");

        s_onegin_dtor(s_onegin);

        return CLOSE_ERROR;
    }

    return SUCCESS;
}

void s_onegin_dtor(char *s_onegin[]) {
    for (int i = 0; i < LEN_OF_FILE; ++i) {
        free(s_onegin[i]);
    }
}