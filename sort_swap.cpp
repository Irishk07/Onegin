#include "sort_swap.h"

#include "string_functions.h"

#include <assert.h>
#include <ctype.h>

void strswap(info_about_strings *onegin_strings, int strok1, int strok2) {
    assert(onegin_strings != NULL);

    char *temp = onegin_strings[strok1].point;
    onegin_strings[strok1].point = onegin_strings[strok2].point;
    onegin_strings[strok2].point = temp;
}


void begin_skip_no_alpha(const char **pointer) {
    while((isalpha(**pointer) == 0 || isspace(**pointer) != 0) && **pointer != '\0') {
        (*pointer)++;
    }
}

int begin_comparator(const void * param1, const void * param2) {
    const char * v1 = *(const char **)param1;
    const char * v2 = *(const char **)param2;

    begin_skip_no_alpha(&v1);
    begin_skip_no_alpha(&v2);

    while(*v1 != '\0' && (*v1 == *v2)) {
        (v1)++;
        (v2)++;

        begin_skip_no_alpha(&v1);
        begin_skip_no_alpha(&v2);

        if (*v1 == '\0' || *v2 == '\0') {
            break;
        }
    }

    return (*v1 - *v2);
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
    while((isalpha(**now_pointer) == 0 || isspace(**now_pointer) != 0) && (*now_pointer != begin_pointer)) {
        (*now_pointer)--;
    }
}

int end_comparator(const void * param1, const void * param2) {
    char *p1_begin = ((info_about_strings *)param1)->point;
    int now_size1 = ((info_about_strings *)param1)->size;
    char *p1_now = p1_begin + now_size1 - 1;

    char *p2_begin = ((info_about_strings *)param2)->point;
    int now_size2 = ((info_about_strings *)param2)->size;
    char *p2_now = p2_begin + now_size2 - 1;

    skip_no_alpha_end(&p1_now, p1_begin);
    skip_no_alpha_end(&p2_now, p2_begin);

    while(p1_now != p1_begin && (*p1_now == *p2_now)) {
        (p1_now)--;
        (p2_now)--;

        skip_no_alpha_end(&p1_now, p1_begin);
        skip_no_alpha_end(&p2_now, p2_begin);

        if (p1_now == p1_begin || p2_now == p2_begin) {
            break;
        }
    }

    return (*p1_now - *p2_now);
}


int point_comparator(const void * param1, const void * param2) {
    char *p1 = ((info_about_strings *)param1)->point;
    char *p2 = ((info_about_strings *)param2)->point;

    return (int)(p1 - p2);
}