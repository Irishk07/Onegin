#include "input.h"

#include "main.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char *read_onegin(int *cnt_strok, int *text_size) {
    assert(cnt_strok != NULL);
    assert(text_size != NULL);

    FILE *text = fopen("Onegin.txt", "r");
    const char *text_name = "Onegin.txt";

    struct stat text_info;
    stat(text_name, &text_info);

    *text_size = (int)text_info.st_size;

    char * text_onegin = (char*)calloc((size_t)(*text_size + 1), sizeof(char));
    char * temp_text_onegin = text_onegin;

    fread((char *)text_onegin, sizeof(char), (size_t)*text_size, text);

    for ( ; *text_onegin != '\0'; ++text_onegin) {
        if (*text_onegin == '\n') {
            //*t_text_onegin = '\0';
            *cnt_strok = *cnt_strok + 1;
        }
    }

    fclose(text);

    return temp_text_onegin;
}

void fill_array_onegin(info_about_strings *onegin_strings, char * text_onegin, int cnt_strok) {
    assert(onegin_strings != NULL);
    assert(text_onegin != NULL);

    onegin_strings[0].point = text_onegin++;

    int size_now = 0;
    for (int i = 1; i < cnt_strok && *text_onegin != '\0'; ) {
        ++size_now;

        if (*text_onegin == '\n') {
            onegin_strings[i].point = (text_onegin + 1);
            onegin_strings[i].size = size_now;

            *text_onegin = '\0';

            size_now = 0;

            ++i;
        }

        text_onegin++;
    }
}