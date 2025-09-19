#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#include "input.h"
#include "sort_swap.h"
#include "put_dtor.h"

int main() {
    int cnt_strok = 0;
    int text_size = 0;

    status status_of_work = SUCCESS;

    const char *text_name = NULL;
    char * text_onegin = NULL;
    info_about_strings *onegin_strings = {};
    const char *text_name_sort = NULL;
    FILE *text_sort = NULL;
    const char *explanation = NULL;

    text_name = "Onegin.txt";
    text_onegin = read_onegin(&cnt_strok, &text_size, text_name, &status_of_work);
    if (status_of_work == FAILED) {
        FAIL;
    }

    onegin_strings = (info_about_strings*)calloc((size_t)cnt_strok, sizeof(info_about_strings));
    if (onegin_strings == NULL) { 
        FAIL;
    }

    fill_array_onegin(onegin_strings, text_onegin, cnt_strok);

    text_name_sort = "Onegin_sort.txt";
    text_sort = fopen(text_name_sort, "w");
    if (text_sort == NULL) {
        FAIL;
    }

    //buble_sort_begin(onegin_strings, cnt_strok);
    qsort(onegin_strings, (size_t)cnt_strok, sizeof(info_about_strings), &begin_comparator);
    explanation = "You can see Pushkin's great work sorted in ascending order from the begginning of the lines";
    puts_onegin(onegin_strings, cnt_strok, text_sort, explanation);

    qsort(onegin_strings, (size_t)cnt_strok, sizeof(info_about_strings), &end_comparator);
    explanation = "You can see Pushkin's great work sorted in ascending order from the end of the lines";
    puts_onegin(onegin_strings, cnt_strok, text_sort, explanation);

    qsort(onegin_strings, (size_t)cnt_strok, sizeof(info_about_strings), &point_comparator);
    explanation = "You can see Pushkin's great work in its original form\n(using a cringe ascending pointers sorting)";
    puts_onegin(onegin_strings, cnt_strok, text_sort, explanation);

    explanation = "You can see Pushkin's great work in its original form\n(using a buffer that hasn't been modified)";
    print_buf_to_file(text_onegin, text_sort, text_size, explanation);

    if (fclose(text_sort) == EOF) {
        FAIL;
    }

    onegin_dtor(text_onegin, onegin_strings);

    return 0;

    exits:
        perror("Error is");

        onegin_dtor(text_onegin, onegin_strings);

        return -1;
}