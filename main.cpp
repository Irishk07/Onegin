#include "main.h"

#include "first.h"
#include "second.h"
#include "third.h"

#include <stdio.h>
#include <stdlib.h>

int main() {

    //frist

    // char f_onegin[LEN_OF_FILE][LEN_OF_LINE] = {{}};

    // f_read_onegin(f_onegin);

    // f_buble_sort(LEN_OF_FILE, f_onegin);

    // f_puts_onegin(LEN_OF_FILE, f_onegin);


    //second

    // const char * s_onegin[LEN_OF_FILE] = {};

    // s_read_onegin(s_onegin);

    // s_buble_sort(s_onegin);

    // s_puts_onegin(s_onegin);

    // s_onegin_dtor(s_onegin);


    //third

    int cnt_strok = 0;
    int text_size = 0;

    char *t_text_onegin = t_read_onegin(&cnt_strok, &text_size);

    const char **t_points_onegin = (const char**)calloc((size_t)(cnt_strok + 1), sizeof(char *));

    t_fill_array_onegin(t_points_onegin, t_text_onegin, text_size);

    t_buble_sort(t_points_onegin, cnt_strok);

    t_puts_onegin(t_points_onegin, cnt_strok);

    t_onegin_dtor(t_text_onegin, t_points_onegin);

    return 0;
}