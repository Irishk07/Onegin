#include "main.h"

#include "first.h"
#include "second.h"

#include <stdio.h>

int main() {

    // char f_onegin[LEN_OF_FILE][LEN_OF_LINE] = {{}};

    // f_read_onegin(f_onegin);

    // f_buble_sort(LEN_OF_FILE, f_onegin);

    // f_puts_onegin(LEN_OF_FILE, f_onegin);

    const char * s_onegin[LEN_OF_FILE] = {};

    s_read_onegin(s_onegin);

    s_buble_sort(s_onegin);

    s_puts_onegin(s_onegin);

    s_onegin_dtor(s_onegin);

    return 0;
}