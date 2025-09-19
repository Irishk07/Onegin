#ifndef INPUT_H_
#define INPUT_H_

#include "main.h"

int size_of_text(const char *text_name);

char *read_onegin(int *cnt_strok, int *text_size, const char *text_name, status *status_of_work);

void fill_array_onegin(info_about_strings *onegin_strings, char *text_onegin, int cnt_strok);

#endif //INPUT_H_