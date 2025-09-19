#ifndef PUT_DTOR_
#define PUT_DTOR_

#include "main.h"

struct info_about_strings {
    char *point = NULL;
    int size = 0;
};

struct about_text {
    char *text_onegin = NULL;
    int cnt_strok = 0;
    int text_size = 0;
};

struct all_onegin {
    info_about_strings *onegin_strings;
    about_text about_onegin_text;
};

status onegin_ctor(const char *text_name, all_onegin *onegin);

void onegin_dtor(all_onegin *onegin);

#endif //PUT_DTOR