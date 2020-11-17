#include <stdio.h>

#define WORD_SIZE 20

int bubbleman(int alive) {
    return (alive) ? 0b10000000 : 0b10000000000; // C3 / D1
}

int airman(int alive) {
    return (alive) ? 0b100000000000 : 0b100000000000000000; // D2 / E3
}

int quickman(int alive) {
    return (alive) ? 0b100000000 : 0b1000; // C4 / B4
}

int woodman(int alive) {
    return (alive) ? 0b10000 : 0b1000000000000; // B5 / D3
}

int crashman(int alive) {
    return (alive) ? 0b10000000000000000 : 0b1000000000; // E2 / C5
}

int flashman(int alive) {
    return (alive) ? 0b01000000000000000000 : 0b100000; // E4 / C1
}

int metalman(int alive) {
    return (alive) ? 0b1000000000000000 : 0b10000000000000000000; // E1 / E5
}
int heatman(int alive) {
    return (alive) ? 0b100000000000000 : 0b10; //  D5 / B2
}
    
int etanks(const unsigned char amount) {

    unsigned int etanks = (1 << (20 + amount));
    return etanks;
}

int bitSet(unsigned int bits, unsigned short pos) {

    return ( (bits & (1 << (pos - 1))) != 0);
}

void decodePassword(unsigned int bits, char letter, const short OFFSET) {

    for (int i = 0; i < 5; i++) {
        if (bitSet(bits, (OFFSET + i ))) {
            printf("%c%i\n", letter, (i + 1));
        }
    }
}

void decode(const unsigned int bits) {
    decodePassword(bits, 'A', 21); // offset +1 (bit number 21... 1-indexed)
    decodePassword(bits, 'E', 16);
    decodePassword(bits, 'D', 11);
    decodePassword(bits, 'C', 6);
    decodePassword(bits, 'B', 1);
}

int main() {

    unsigned int bits = 0x00;

    bits = bits | bubbleman(0);
    bits = bits | airman(0);
    bits = bits | quickman(1);
    bits = bits | woodman(1);
    bits = bits | crashman(1);
    bits = bits | flashman(1);
    bits = bits | metalman(1);
    bits = bits | heatman(1);

    //printf("etanks 0 (alone): %i\n", etanks(0));
    bits = rotateLeft(bits);
    bits = bits | (etanks(2));
    /*
        etanks: 5 bits
            00001 // 0 etanks
            00010 // 1 etank
            00100 // 2 etanks
            01000 // 3 etanks
            10000 // 4 etanks
    */
    printf("after rotation: %i\n", bits);

    decode(bits);

    return 0;
}
