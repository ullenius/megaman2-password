#include <stdio.h>
#include <getopt.h>
#include "password.h"

int main(int argc, char** argv) {
        
    int defeated = 1;
    printf("defeated before reading options: %i\n", defeated);

    struct option longopts[] = {
        { "heatman", no_argument, &defeated, 0 } // no_argument == 0
    };

    while ( (getopt_long(argc, argv, "", longopts, NULL)) != EOF) {


        argc = argc - optind; // skip past the options we've read
        argv = argv + optind;
    }
    printf("defeated after: %i\n", defeated);

    generatePassword();

    return 0;
}
