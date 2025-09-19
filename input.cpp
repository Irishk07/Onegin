#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "input.h"

#include "main.h"

int size_of_text(const char *text_name) {
    struct stat text_info = {};

    if (stat(text_name, &text_info) == -1) {
        return -1;
    }

    return (int)text_info.st_size;
}

char *read_onegin(int *cnt_strok, int *text_size, const char *text_name, status *status_of_work) {
    assert(cnt_strok != NULL);
    assert(text_size != NULL);

    FILE *text = fopen(text_name, "r");
    if (text == NULL) {
        *status_of_work = FAILED;

        return NULL;
    }

    *text_size = size_of_text(text_name);
    if (*text_size == -1) {
        *status_of_work = FAILED;

        return NULL;
    }

    char * text_onegin = (char*)calloc((size_t)(*text_size + 1), sizeof(char));
    if (text_onegin == NULL) {
        *status_of_work = FAILED;

        return NULL;
    }

    char * temp_text_onegin = text_onegin;

    fread((char *)text_onegin, sizeof(char), (size_t)*text_size, text);
    if (ferror(text) != 0) {
        fprintf(stderr, "Error is: problem with reading file");
        *status_of_work = FAILED_DONE;

        free(text_onegin);

        return NULL;
    }

    for ( ; *text_onegin != '\0'; ++text_onegin) {
        if (*text_onegin == '\n') {
            *cnt_strok = *cnt_strok + 1;
        }
    }

    if (fclose(text) == EOF) {
        *status_of_work = FAILED;

        return NULL; 
    }

    return temp_text_onegin;
}

void fill_array_onegin(info_about_strings *onegin_strings, char * text_onegin, int cnt_strok) {
    assert(onegin_strings != NULL);
    assert(text_onegin != NULL);

    onegin_strings[0].point = text_onegin;

    int size_now = 0;
    for (int i = 0; i < cnt_strok && *text_onegin != '\0'; ) {
        ++size_now;

        if (*text_onegin == '\n') {
            if (i < cnt_strok - 1) {
                onegin_strings[i + 1].point = (text_onegin + 1);
            }
            
            onegin_strings[i].size = size_now;

            *text_onegin = '\0';

            size_now = 0;

            ++i;
        }

        text_onegin++;
    }
}