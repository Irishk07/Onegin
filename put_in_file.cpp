#include <stdio.h>
#include <stdlib.h>

#include "put_in_file.h"

#include "assert.h"
#include "ctor_dtor.h"
#include "main.h"
#include "sort_swap.h"


status sort_and_put(const char *text_name_sort, all_onegin *onegin) {
    FILE *text_sort = fopen(text_name_sort, "w");
    if (text_sort == NULL) {
        return OPEN_ERROR;
    }

    //buble_sort_begin(onegin_strings, cnt_strok);
    qsort(onegin->onegin_strings, (size_t)(onegin->about_onegin_text.cnt_strok), sizeof(info_about_strings), &begin_comparator);
    const char *explanation = "You can see Pushkin's great work sorted in ascending order from the begginning of the lines";
    puts_onegin(onegin, text_sort, explanation);

    qsort(onegin->onegin_strings, (size_t)(onegin->about_onegin_text.cnt_strok), sizeof(info_about_strings), &end_comparator);
    explanation = "You can see Pushkin's great work sorted in ascending order from the end of the lines";
    puts_onegin(onegin, text_sort, explanation);

    qsort(onegin->onegin_strings, (size_t)(onegin->about_onegin_text.cnt_strok), sizeof(info_about_strings), &point_comparator);
    explanation = "You can see Pushkin's great work in its original form\n"
                  "(using a cringe ascending pointers sorting)";
    puts_onegin(onegin, text_sort, explanation);

    explanation = "You can see Pushkin's great work in its original form\n"
                  "(using a buffer that hasn't been modified)";
    print_buf_to_file(onegin, text_sort, explanation);

    if (fclose(text_sort) == EOF) {
        return CLOSE_ERROR;
    }

    return SUCCESS;
}

void print_buf_to_file(all_onegin *onegin, FILE *text_sort, const char *explanation) {
    fprintf(text_sort, "%s\n", explanation);
    fputc('\n', text_sort);

    for (int i = 0; i < onegin->about_onegin_text.text_size; ++i) {
        (onegin->about_onegin_text.text_onegin[i] == '\0') ? fputc('\n', text_sort) : fputc(onegin->about_onegin_text.text_onegin[i], text_sort);
    }
}

void puts_onegin(all_onegin *onegin, FILE *text_sort, const char *explanation) {
    assert(onegin->onegin_strings != NULL);
    assert(explanation != NULL);

    fprintf(text_sort, "%s\n", explanation);
    fputc('\n', text_sort);

    for (int i = 0; i < onegin->about_onegin_text.cnt_strok; ++i) {
        fprintf(text_sort, "%s", onegin->onegin_strings[i].point);
        fputc('\n', text_sort);
    }

    fputc('\n', text_sort);
}