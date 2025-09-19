#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "read_and_fill.h"

#include "main.h"
#include "ctor_dtor.h"


int size_of_text(const char *text_name) {
    struct stat text_info = {};

    if (stat(text_name, &text_info) == -1) {
        perror("Error is");

        return -1;
    }

    return (int)text_info.st_size;
}

//char *read_onegin(int *cnt_strok, int *text_size, const char *text_name, status *status_of_work)
status read_onegin(all_onegin *onegin, const char *text_name, status *status_of_work) {
    assert(onegin != NULL);
    assert(onegin->onegin_strings == NULL);    
    assert(status_of_work != NULL);

    FILE *text = fopen(text_name, "r");
    if (text == NULL) {
        perror("Error is");
        return OPEN_ERROR;
    }

    onegin->about_onegin_text.text_size = size_of_text(text_name);
    if (onegin->about_onegin_text.text_size == -1) {
        return STAT_ERROR;
    }

    onegin->about_onegin_text.text_onegin = (char*)calloc((size_t)(onegin->about_onegin_text.text_size + 1), sizeof(char));
    if (onegin->about_onegin_text.text_onegin == NULL) {
        perror("Error is");
        return CALLOC_ERROR;
    }

    char *temp_text_onegin = onegin->about_onegin_text.text_onegin;

    fread((char *)onegin->about_onegin_text.text_onegin, sizeof(char), (size_t)onegin->about_onegin_text.text_size, text);
    if (ferror(text) != 0) {
        fprintf(stderr, "Error is: problem with reading file");

        free(onegin->about_onegin_text.text_onegin);

        return READ_ERROR;
    }

    for ( ; *temp_text_onegin != '\0'; ++temp_text_onegin) {
        if (*temp_text_onegin == '\n') {
            onegin->about_onegin_text.cnt_strok = onegin->about_onegin_text.cnt_strok + 1;
        }
    }

    if (fclose(text) == EOF) {
        perror("Error is");
        return CLOSE_ERROR; 
    }

    return SUCCESS;
}

void fill_array_onegin(all_onegin *onegin) {
    assert(onegin->onegin_strings != NULL);
    assert(onegin->about_onegin_text.text_onegin != NULL);

    char *temp_text_onegin = onegin->about_onegin_text.text_onegin;

    onegin->onegin_strings[0].point = temp_text_onegin;

    int size_now = 0;
    for (int i = 0; i < onegin->about_onegin_text.cnt_strok && *temp_text_onegin != '\0'; ) {
        ++size_now;

        if (*temp_text_onegin == '\n') {
            if (i < onegin->about_onegin_text.cnt_strok - 1) {
                onegin->onegin_strings[i + 1].point = (temp_text_onegin + 1);
            }
            
            onegin->onegin_strings[i].size = size_now;

            *temp_text_onegin = '\0';

            size_now = 0;

            ++i;
        }

        temp_text_onegin++;
    }
}