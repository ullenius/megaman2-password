#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "password.h"

void printHelp() {

   printf(
    "Usage: mm2pwd [option]\n\n"
    "[--etanks <number>]\n\n"
    "Defeated robot master:\n"
    "\t[--airman]\n"
    "\t[--bubbleman]\n"
    "\t[--crashman]\n"
    "\t[--flashman]\n"
    "\t[--heatman]\n"
    "\t[--metalman]\n"
    "\t[--woodman]\n"
    "\t[--quickman]\n\n"
    "--debug\t Print password as hex integer only\n"
    "--help\t Print help text\n"
    );
}

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
    config.debug =      0;
        
    struct option longopts[] = {
        { "bubbleman", no_argument, &config.bubbleman, 0 }, // no_argument == 0
        { "airman", no_argument, &config.airman, 0 },
        { "quickman", no_argument, &config.quickman, 0 },
        { "woodman", no_argument, &config.woodman, 0 },
        { "crashman", no_argument, &config.crashman, 0 },
        { "flashman", no_argument, &config.flashman, 0 },
        { "metalman", no_argument, &config.metalman, 0 },
        { "heatman", no_argument, &config.heatman, 0 },
        { "etanks", required_argument, NULL, 'e' },
        { "debug", no_argument, NULL, 'd' },
        { "help", no_argument, NULL, 'h' },
        { 0, 0, 0, 0 }
    };

    char ch;
    while ( (ch = getopt_long(argc, argv, "", longopts, NULL)) != -1) {
        switch (ch) {
            case 'd':
            config.debug = 1;
            break;
            case 'e':
            config.etanks = atoi(optarg);
            break;
            case 'h':
            case '?':
            printHelp();
            return 0;
            break;
            case 0: // getopt_long set a variable, just keep going
            break;
        }
    }
    if (argc == 1) {
        printHelp();
        return -1;
    }

    generatePassword(&config);

    return 0;
}
