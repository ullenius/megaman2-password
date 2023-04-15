#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "password.h"

#define WORD_SIZE 20
#define MAX_ETANKS 4 // 0-4

// beaten = 0, alive = 1
uint32_t bubbleman(uint32_t alive) {
    return alive ? 1 << 7 : 1 << 10; // C3 / D1
}

uint32_t airman(uint32_t alive) {
    return alive ? 1 << 11 : 1 << 17; // D2 / E3
}

uint32_t quickman(uint32_t alive) {
    return alive ? 1 << 8 : 1 << 3; // C4 / B4
}

uint32_t woodman(uint32_t alive) {
    return alive ? 1 << 4 : 1 << 12; // B5 / D3
}

uint32_t crashman(uint32_t alive) {
    return alive ? 1 << 16 : 1 << 9; // E2 / C5
}

uint32_t flashman(uint32_t alive) {
    return alive ? 1 << 18: 1 << 5; // E4 / C1
}

uint32_t metalman(uint32_t alive) {
    return alive ? 1 << 15: 1 << 19; // E1 / E5
}

uint32_t heatman(uint32_t alive) {
    return alive ? 1 << 14 : 1 << 1; //  D5 / B2
}
    
uint32_t etanks(const uint8_t amount) {
    uint32_t etanks = (1 << (WORD_SIZE + amount));
    return etanks;
}

uint32_t bitSet(const uint32_t bits, const uint8_t pos) {
    return ( (bits & (1 << (pos - 1))) != 0);
}

void decodePassword(const uint32_t bits, const char letter, const uint8_t OFFSET) {
    for (int i = 0; i < 5; i++) {
        if (bitSet(bits, (OFFSET + i ))) {
            printf("%c%i ", letter, (i + 1));
        }
    }
}

void decode(const uint32_t bits) {
    decodePassword(bits, 'A', 21); // offset +1 (bit number 21... 1-indexed)
    decodePassword(bits, 'B', 1);
    decodePassword(bits, 'C', 6);
    decodePassword(bits, 'D', 11);
    decodePassword(bits, 'E', 16);
}

/*
    Circular left shift of words E-B (bits 1-20) depending on the number of
    etanks. Clears out e-tanks (A-word) if set.

    Call this function *before* etanks()
*/
uint32_t rotateLeft(const uint32_t bits, const uint8_t ETANKS) {
    assert(ETANKS <= MAX_ETANKS);
    if (ETANKS == 0) {
        return bits;
    }
    const uint32_t mask = 0xFFFFF; // bits 1-20

    // clear first 5 bits used for etanks (A word)
    // left rotation of bits by 1-4 steps. 
    // 20 bit word size
    const uint32_t leftmost = (bits & mask) >> (WORD_SIZE - ETANKS);

    // we only keep the rightmost 20 bits
    const uint32_t rightmost = (bits << ETANKS) & mask;

    return leftmost | rightmost;
}

uint32_t generatePassword(struct options* config) {
    uint32_t bits = 0;
    const uint8_t ETANKS = config->etanks;

    bits = bits | bubbleman( config->bubbleman );
    bits = bits | airman( config->airman );
    bits = bits | quickman( config->quickman);
    bits = bits | woodman( config->woodman);
    bits = bits | crashman( config->crashman);
    bits = bits | flashman( config->flashman);
    bits = bits | metalman( config->metalman);
    bits = bits | heatman( config->heatman);

    bits = rotateLeft(bits, ETANKS);
    bits = bits | etanks(ETANKS);

    if (config->debug) {
        printf("0x%x\n", bits);
        return bits;
    }
    decode(bits);
    printf("\n");
    return 0;
}
