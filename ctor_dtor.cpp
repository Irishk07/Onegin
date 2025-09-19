#include <assert.h>
#include <stdlib.h>

#include "ctor_dtor.h"

#include "main.h"
#include "read_and_fill.h"


status onegin_ctor(const char *text_name, all_onegin *onegin) {
    status status_of_work = SUCCESS;

    read_onegin(onegin, text_name, &status_of_work);
    if (status_of_work != SUCCESS) {
        return status_of_work;
    }

    onegin->onegin_strings = (info_about_strings*)calloc((size_t)((onegin->about_onegin_text).cnt_strok), sizeof(info_about_strings));
    if (onegin->onegin_strings == NULL) {
        return CALLOC_ERROR;
    }

    fill_array_onegin(onegin);

    return SUCCESS;
}

void onegin_dtor(all_onegin *onegin) {
    assert(onegin->onegin_strings != NULL);
    assert(onegin->about_onegin_text.text_onegin != NULL);
    
    free(onegin->onegin_strings);
    free(onegin->about_onegin_text.text_onegin);
}