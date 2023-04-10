#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "password.h"

void beatAllMaxEtanks() {
    options config;
    config.etanks =     4;
    // beaten = 0, alive = 1
    config.bubbleman =  0;
    config.airman =     0;
    config.quickman =   0;
    config.woodman =    0;
    config.crashman =   0;
    config.flashman =   0;
    config.metalman =   0;
    config.heatman =    0;
    config.debug =      1;

    const uint32_t ACTUAL = generatePassword(&config);
    const uint32_t EXPECTED = 0x10162AA;
    assert(EXPECTED == ACTUAL);
}

void beatAllZeroEtanks() {
    options config;
    config.etanks =     0;
    config.bubbleman =  0;
    config.airman =     0;
    config.quickman =   0;
    config.woodman =    0;
    config.crashman =   0;
    config.flashman =   0;
    config.metalman =   0;
    config.heatman =    0;
    config.debug =      1;

    const uint32_t ACTUAL = generatePassword(&config);
    const uint32_t EXPECTED = 0x1A162A;
    assert(EXPECTED == ACTUAL);
}

void fourBeatenAndTwoTanks() {
    options config;
    config.etanks =     2;
    config.bubbleman =  1;
    config.airman =     1;
    config.quickman =   0;
    config.woodman =    0;
    config.crashman =   0;
    config.flashman =   0;
    config.metalman =   1;
    config.heatman =    1;
    config.debug =      1;

    const uint32_t ACTUAL = generatePassword(&config);
    const uint32_t EXPECTED = 0x436AA0;
    assert(EXPECTED == ACTUAL);
}

void twoBeatenAndTwoTanks() {
    options config;
    config.etanks =     2;
    config.bubbleman =  0;
    config.airman =     0;
    config.quickman =   1;
    config.woodman =    1;
    config.crashman =   1;
    config.flashman =   1;
    config.metalman =   1;
    config.heatman =    1;
    config.debug =      1;

    const uint32_t ACTUAL = generatePassword(&config);
    const uint32_t EXPECTED = 0x4F1441;
    assert(EXPECTED == ACTUAL);
}

int main() {
    twoBeatenAndTwoTanks();
    beatAllZeroEtanks();
    beatAllMaxEtanks();
    fourBeatenAndTwoTanks();

    printf("All unit tests successfully passed!\n");
    return 0;
}
