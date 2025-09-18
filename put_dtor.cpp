#include <assert.h>
#include <stdlib.h>

#include "put_dtor.h"

#include "main.h"

void puts_onegin(info_about_strings *onegin_strings, int cnt_strok, FILE * text_sort) {
    assert(onegin_strings != NULL);

    for (int i = 0; i < cnt_strok; ++i) {
        fprintf(text_sort, "%s", onegin_strings[i].point);
        fputc('\n', text_sort);
    }

    fputc('\n', text_sort);
    fprintf(text_sort, "NEXTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT\n");
    fputc('\n', text_sort);

}

void onegin_dtor(char *text_onegin, info_about_strings *onegin_strings) {
    assert(onegin_strings != NULL);
    assert(text_onegin != NULL);
    
    free(text_onegin);
    free(onegin_strings);
}