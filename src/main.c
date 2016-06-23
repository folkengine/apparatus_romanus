#include "roman.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printInfo()
{
    printf("Apparatus numero Romanus\n");
    printf("    Christus Pistor (c) MMXVI\n");
    printf("    SPQR\n\n");
    printf("consuetudinem: roman [-s] <augend> <addend>\n\n");
    printf("eligendi:\n");
    printf("    -s\tsubtracta\n\n");
}

int main(int argc, char **argv)
{
    int add = 1;
    char *result = malloc(100);
    int c;
    int index;

    // Parse flags
    while ((c = getopt(argc, argv, "s:")) != -1) {
        switch (c) {
            case 's':
                add = 0;
                break;
            default:
                printInfo();
                return 0;
        }
    }

    // Insure that we have the correct u
    if (argc < 2) {
        printInfo();
        return 0;
    }

    index = optind;

    if (add) {
        for (index = optind; index < argc; index++) {
            strcpy(result, add_roman(result, argv[index]));
        }
    } else {
        // We're doing subtraction so grab the 3rd arg as minuend and subtract the rest.
        strcpy(result, argv[2]);
        for (3; index < argc; index++) {
            strcpy(result, subtract_roman(result, argv[index]));
        }
    }
    printf("    SVMMA: %s\n", result);

    free(result);
    return 0;
}