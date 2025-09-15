#include "third.h"

#include "main.h"
#include "string_functions.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char *t_read_onegin(int *cnt_strok, int *text_size) {
    assert(cnt_strok != NULL);
    assert(text_size != NULL);

    FILE *text = fopen("Onegin.txt", "r");
    const char *text_name = "Onegin.txt";

    struct stat text_info;
    stat(text_name, &text_info);

    *text_size = (int)text_info.st_size;

    char *t_text_onegin = (char*)calloc((size_t)*text_size + 1, sizeof(char));
    char *temp_text_onegin = t_text_onegin;

    fread(t_text_onegin, sizeof(char), (size_t)*text_size, text);

    for ( ; *t_text_onegin != '\0'; ++t_text_onegin) {
        if (*t_text_onegin == '\n') {
            *t_text_onegin = '\0';
            *cnt_strok = *cnt_strok + 1;
        }
    }

    fclose(text);

    return temp_text_onegin;
}

void t_fill_array_onegin(const char **t_points_onegin, char *t_text_onegin, int text_size) {
    assert(t_points_onegin != NULL);
    assert(t_text_onegin != NULL);

    *t_points_onegin++ = t_text_onegin;

    for (int i = 0; i < text_size; ++i) {
        if (t_text_onegin[i] == '\0') {
            *(t_points_onegin++) = (t_text_onegin + i + 1);
        }
    }
}

void t_strswap(const char **t_points_onegin, int strok1, int strok2) {
    assert(t_points_onegin != NULL);

    const char *temp = t_points_onegin[strok1];
    t_points_onegin[strok1] = t_points_onegin[strok2];
    t_points_onegin[strok2] = temp;
}

void t_buble_sort(const char **t_points_onegin, int cnt_strok) {
    assert(t_points_onegin != NULL);

    for (int i = 0; i < cnt_strok; ++i) {
        for (int j = 0; j < cnt_strok - i - 1; ++j) {
            if (t_points_onegin[j] == NULL || t_points_onegin[j + 1] == NULL) { //FIXME
                continue;
            }
            
            if (my_strcmp(t_points_onegin[j], t_points_onegin[j + 1]) > 0) {
                t_strswap(t_points_onegin, j, j + 1);
            }
        }
    }
}

void t_puts_onegin(const char **t_points_onegin, int cnt_strok) {
    assert(t_points_onegin != NULL);

    FILE *text_sort = fopen("Onegin_sort.txt", "w");

    for (int i = 0; i < cnt_strok; ++i) {
        if (t_points_onegin[i] == NULL) { //FIXME
            continue;
        }

        fprintf(text_sort, "%s", t_points_onegin[i]);
        fputc('\n', text_sort);
    }

    fclose(text_sort);
}

void t_onegin_dtor(char *t_text_onegin, const char **t_points_onegin) {
    assert(t_points_onegin != NULL);
    assert(t_text_onegin != NULL);
    
    free((void *)t_text_onegin);
    free((void *)t_points_onegin);
}