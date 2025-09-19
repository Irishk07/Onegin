#include <assert.h>
#include <stdlib.h>

#include "put_dtor.h"

#include "main.h"

void print_buf_to_file(char *text_onegin, FILE *text_sort, int text_size, const char * explanation) {
    fprintf(text_sort, "%s\n", explanation);
    fputc('\n', text_sort);

    for (int i = 0; i < text_size; ++i) {
        (text_onegin[i] == '\0') ? fputc('\n', text_sort) : fputc(text_onegin[i], text_sort);
    }
}

void puts_onegin(info_about_strings *onegin_strings, int cnt_strok, FILE * text_sort, const char * explanation) {
    assert(onegin_strings != NULL);
    assert(explanation != NULL);

    fprintf(text_sort, "%s\n", explanation);
    fputc('\n', text_sort);

    for (int i = 0; i < cnt_strok; ++i) {
        fprintf(text_sort, "%s", onegin_strings[i].point);
        fputc('\n', text_sort);
    }

    fputc('\n', text_sort);
}

void onegin_dtor(char *text_onegin, info_about_strings *onegin_strings) {
    assert(onegin_strings != NULL);
    assert(text_onegin != NULL);
    
    free(text_onegin);
    free(onegin_strings);
}