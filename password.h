#ifndef PASSWORD_H
#define PASSWORD_H

#include <stdint.h>

struct options {
    int airman;
    int bubbleman;
    int crashman;
    int flashman;
    int heatman;
    int metalman;
    int quickman;
    int woodman;
    int etanks;
    int debug;
};

extern uint32_t generatePassword(struct options* config);
#endif
