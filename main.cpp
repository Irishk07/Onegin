#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#include "input.h"
#include "sort_swap.h"
#include "put_dtor.h"

int main() {
    int cnt_strok = 0;
    int text_size = 0;

    const char *text_name = "Onegin.txt";
    char * text_onegin = read_onegin(&cnt_strok, &text_size, text_name);
    if (text_onegin == NULL) {
        return -1;
    }

    info_about_strings *onegin_strings = (info_about_strings*)calloc((size_t)cnt_strok, sizeof(info_about_strings));
    if (onegin_strings == NULL) { 
        perror("Error is");

        onegin_dtor(text_onegin, onegin_strings);

        return -1;
    }

    fill_array_onegin(onegin_strings, text_onegin, cnt_strok);

    const char *text_name_sort = "Onegin_sort.txt";
    FILE *text_sort = fopen(text_name_sort, "w");
    if (text_sort == NULL) {
        perror("Error is");

        onegin_dtor(text_onegin, onegin_strings);

        return -1;
    }

    //buble_sort_begin(onegin_strings, cnt_strok);
    qsort(onegin_strings, (size_t)cnt_strok, sizeof(info_about_strings), &begin_comparator);
    puts_onegin(onegin_strings, cnt_strok, text_sort);

    qsort(onegin_strings, (size_t)cnt_strok, sizeof(info_about_strings), &end_comparator);
    puts_onegin(onegin_strings, cnt_strok, text_sort);

    qsort(onegin_strings, (size_t)cnt_strok, sizeof(info_about_strings), &point_comparator);
    puts_onegin(onegin_strings, cnt_strok, text_sort);

    if (fclose(text_sort)) {
        perror("Error is");

        onegin_dtor(text_onegin, onegin_strings);
        
        return -1;
    }

    onegin_dtor(text_onegin, onegin_strings);

    return 0;
}