#include <stdio.h>
#include <assert.h>

#define WORD_SIZE 20
#define MAX_ETANKS 4 // 0-4

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

    unsigned int etanks = (1 << (WORD_SIZE + amount));
    return etanks;
}

int bitSet(const unsigned int bits, const unsigned short pos) {

    return ( (bits & (1 << (pos - 1))) != 0);
}

void decodePassword(const unsigned int bits, const char letter, const short OFFSET) {

    for (int i = 0; i < 5; i++) {
        if (bitSet(bits, (OFFSET + i ))) {
            printf("%c%i ", letter, (i + 1));
        }
    }
    printf("\n");
}

void decode(const unsigned int bits) {
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
unsigned int rotateLeft(const unsigned int bits, const unsigned short ETANKS) {

    assert(ETANKS <= MAX_ETANKS);
    if (ETANKS == 0) {
        return bits;
    }

    // clear first 5 bits used for etanks (A word)
    unsigned int leftmost = bits & 0xFFFFF;
    // left rotation of bits by 1-4 steps. 
    // 20 bit word size
    leftmost = (bits >> (WORD_SIZE - ETANKS));

    unsigned int rightmost = (bits << ETANKS);
    unsigned int mask = 0xFFFFF; // 20 bits set
    // we only keep the rightmost 20 bits
    rightmost = rightmost & mask;

    unsigned int result = leftmost | rightmost;
    return result;
}

int main() {

    unsigned int bits = 0x00;
    unsigned const short ETANKS = 4;

    bits = bits | bubbleman(0);
    bits = bits | airman(0);
    bits = bits | quickman(0);
    bits = bits | woodman(0);
    bits = bits | crashman(0);
    bits = bits | flashman(0);
    bits = bits | metalman(0);
    bits = bits | heatman(0);

    bits = rotateLeft(bits, ETANKS);
    bits = bits | (etanks(ETANKS));
    printf("after rotation: 0x%x\n", bits);

    decode(bits);

    return 0;
}
