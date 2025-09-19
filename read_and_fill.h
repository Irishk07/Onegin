#ifndef READ_AND_FILL_H_
#define READ_AND_FILL_H_

#include "ctor_dtor.h"


int size_of_text(const char *text_name);

status read_onegin(all_onegin *onegin, const char *text_name, status *status_of_work);

void fill_array_onegin(all_onegin *onegin);

#endif //READ_AND_FILL_H_