#include "sort_swap.h"

#include "string_functions.h"

#include <assert.h>
#include <ctype.h>

void strswap(info_about_strings *onegin_strings, int strok1, int strok2) {
    assert(onegin_strings != NULL);

    info_about_strings temp = onegin_strings[strok1];
                              onegin_strings[strok1] = onegin_strings[strok2];
                                                       onegin_strings[strok2] = temp;
}


void begin_skip_no_alpha(const char **pointer) {
    assert(pointer);
    assert(*pointer);

    while((isalpha(**pointer) == 0 || isspace(**pointer) != 0) && **pointer != '\0') {
        (*pointer)++;
    }
}

int begin_comparator(const void * param1, const void * param2) {
    const char * v1 = *(const char * const *)param1;
    const char * v2 = *(const char * const *)param2;

    begin_skip_no_alpha(&v1);
    begin_skip_no_alpha(&v2);

    while(*v1 != '\0' && (tolower(*v1) == tolower(*v2))) {
        (v1)++;
        (v2)++;

        begin_skip_no_alpha(&v1);
        begin_skip_no_alpha(&v2);

        if (*v1 == '\0' || *v2 == '\0') {
            break;
        }
    }

    return (tolower(*v1) - tolower(*v2));
}

void buble_sort_begin(info_about_strings *onegin_strings, int cnt_strok) {
    assert(onegin_strings != NULL);

    for (int i = 0; i < cnt_strok; ++i) {
        for (int j = 0; j < cnt_strok - i - 1; ++j) {

            if (begin_comparator(&onegin_strings[j].point, &onegin_strings[j + 1].point) > 0) {
                strswap(onegin_strings, j, j + 1);
            }
        }
    }
}


void skip_no_alpha_end(char **now_pointer, char *begin_pointer) {
    while((*now_pointer > begin_pointer) && (!isalpha(**now_pointer) || isspace(**now_pointer))) {
        (*now_pointer)--;
    }
}

int end_comparator(const void * param1, const void * param2) {
    info_about_strings struct1 = *(const info_about_strings*)param1;
    info_about_strings struct2 = *(const info_about_strings*)param2;

    char *p1_now = struct1.point + struct1.size - 1;

    char *p2_now = struct2.point + struct2.size - 1;

    skip_no_alpha_end(&p1_now, struct1.point);
    skip_no_alpha_end(&p2_now, struct2.point);

    while(p1_now != struct1.point && (tolower(*p1_now) == tolower(*p2_now))) {
        (p1_now)--;
        (p2_now)--;

        skip_no_alpha_end(&p1_now, struct1.point);
        skip_no_alpha_end(&p2_now, struct2.point);

        if (p1_now == struct1.point || p2_now == struct2.point) {
            break;
        }
    }

    return (tolower(*p1_now) - tolower(*p2_now));
}


int point_comparator(const void * param1, const void * param2) {
    char *p1 = ((const info_about_strings *)param1)->point;
    char *p2 = ((const info_about_strings *)param2)->point;

    return (int)(p1 - p2);
}