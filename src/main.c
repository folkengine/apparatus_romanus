#include "roman.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *result = malloc(100);
    int index;

    index = optind;

    for (index = optind; index < argc; index++) {
        strcpy(result, add_roman(result, argv[index]));
    }

    printf("    SUM: %s\n", result);

    free(result);
    return 0;
}
