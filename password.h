#ifndef PASSWORD_H
#define PASSWORD_H

#include <stdint.h>

struct options {
    uint32_t airman;
    uint32_t bubbleman;
    uint32_t crashman;
    uint32_t flashman;
    uint32_t heatman;
    uint32_t metalman;
    uint32_t quickman;
    uint32_t woodman;
    uint32_t etanks;
    uint32_t debug;
};

extern uint32_t generatePassword(struct options* config);
#endif
