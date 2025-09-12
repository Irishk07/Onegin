#include "first.h"

int main() {

    char onegin[LEN_OF_FILE][LEN_OF_LINE] = {{}};

    read_onegin(onegin);

    buble_sort(LEN_OF_FILE, onegin);

    puts_onegin(LEN_OF_FILE, onegin);

    return 0;
}