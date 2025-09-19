#ifndef PUT_DTOR_
#define PUT_DTOR_

#include "main.h"

void print_buf_to_file(char *text_onegin, FILE *text_sort, int text_size, const char * explanation);

void puts_onegin(info_about_strings *onegin_strings, int cnt_strok, FILE * text_sort, const char *explanation);

void onegin_dtor(char *text_onegin, info_about_strings *onegin_strings);

#endif //PUT_DTOR