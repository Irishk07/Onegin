#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#include "ctor_dtor.h"
#include "put_in_file.h"
#include "read_and_fill.h"
#include "sort_swap.h"


int main() {
    // info_about_strings onegin_strings = {};
    // about_text about_onegin_text = {};
    all_onegin onegin = {};

    const char *text_name = "Onegin.txt";
    const char *text_name_sort = "Onegin_sort.txt";

    status status_of_work = onegin_ctor(text_name, &onegin);
    if (status_of_work != SUCCESS) {
        FAIL;
    }

    status_of_work = sort_and_put(text_name_sort, &onegin);

exits:
    onegin_dtor(&onegin);

    return status_of_work;
}