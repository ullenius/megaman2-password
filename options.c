#include <stdio.h>
#include <getopt.h>
#include "password.h"

int main(int argc, char** argv) {

    options config;
    config.etanks =     2;
    // beaten = 0, alive = 1
    config.bubbleman =  1;
    config.airman =     1;
    config.quickman =   1;
    config.woodman =    1;
    config.crashman =   1;
    config.flashman =   1;
    config.metalman =   1;
    config.heatman =    1;
        
    int defeated = 1;
    printf("defeated before reading options: %i\n", defeated);

    struct option longopts[] = {
        { "bubbleman", no_argument, &config.heatman, 0 }, // no_argument == 0
        { "airman", no_argument, &config.heatman, 0 },
        { "quickman", no_argument, &config.heatman, 0 },
        { "woodman", no_argument, &config.heatman, 0 },
        { "crashman", no_argument, &config.heatman, 0 },
        { "flashman", no_argument, &config.heatman, 0 },
        { "metalman", no_argument, &config.heatman, 0 },
        { "heatman", no_argument, &config.heatman, 0 },
    };

    while ( (getopt_long(argc, argv, "", longopts, NULL)) != EOF) {


        argc = argc - optind; // skip past the options we've read
        argv = argv + optind;
    }
    printf("defeated after: %i\n", defeated);


    generatePassword(&config);

    return 0;
}
