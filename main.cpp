#include "main.h"

#include "input.h"
#include "sort_swap.h"
#include "put_dtor.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    int cnt_strok = 0;
    int text_size = 0;

    char * text_onegin = read_onegin(&cnt_strok, &text_size);

    info_about_strings *onegin_strings = (info_about_strings*)calloc((size_t)(cnt_strok + 1), sizeof(info_about_strings));

    fill_array_onegin(onegin_strings, text_onegin, text_size);

    FILE *text_sort = fopen("Onegin_sort.txt", "w");
    buble_sort_begin(onegin_strings, cnt_strok);

    puts_onegin(onegin_strings, cnt_strok, text_sort);

    qsort(onegin_strings, cnt_strok + 1, sizeof(info_about_strings), &end_comparator);
    puts_onegin(onegin_strings, cnt_strok, text_sort);

    qsort(onegin_strings, cnt_strok + 1, sizeof(info_about_strings), &point_comparator);
    puts_onegin(onegin_strings, cnt_strok, text_sort);

    fclose(text_sort);

    onegin_dtor(text_onegin, onegin_strings);

    return 0;
}