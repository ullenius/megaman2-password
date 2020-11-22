#include <stdio.h>
#include <stdlib.h>
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
        
    printf("etanks before reading options: %i\n", config.etanks);

    struct option longopts[] = {
        { "bubbleman", no_argument, &config.heatman, 0 }, // no_argument == 0
        { "airman", no_argument, &config.heatman, 0 },
        { "quickman", no_argument, &config.heatman, 0 },
        { "woodman", no_argument, &config.heatman, 0 },
        { "crashman", no_argument, &config.heatman, 0 },
        { "flashman", no_argument, &config.heatman, 0 },
        { "metalman", no_argument, &config.heatman, 0 },
        { "heatman", no_argument, &config.heatman, 0 },
        { "etanks", required_argument, NULL, 'e' }
    };

    char ch;
    while ( (ch = (getopt_long(argc, argv, "", longopts, NULL)) != EOF)) {

        switch (ch) {
            case 'e':
            config.etanks = atoi(optarg);
            break;
            case 0: // getopt_long set a variable, just keep going
            break;
        }

        argc = argc - optind; // skip past the options we've read
        argv = argv + optind;
    }
    printf("etanks after: %i\n", config.etanks);


    generatePassword(&config);

    return 0;
}
