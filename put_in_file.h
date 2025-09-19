#ifndef PUT_IN_FILE
#define PUT_IN_FILE

#include <stdio.h>

#include "ctor_dtor.h"


status sort_and_put(const char *text_name_sort, all_onegin *onegin);

void print_buf_to_file(all_onegin *onegin, FILE *text_sort, const char *explanation);

void puts_onegin(all_onegin *onegin, FILE *text_sort, const char *explanation);

#endif //PUT_IN_FILE