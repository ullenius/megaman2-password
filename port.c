#include <stdio.h>

/*
    11100 11100 11100 11100 
    bits = 0b00000_00000_00000_00000

    # Determine the boss bits (bits 1-20)
    bits |= @bubble_man ? 0b00000_00000_00100_00000 : 0b00000_00001_00000_00000 # C3 / D1
    bits |= @air_man    ? 0b00000_00010_00000_00000 : 0b00100_00000_00000_00000 # D2 / E3
    bits |= @quick_man  ? 0b00000_00000_01000_00000 : 0b00000_00000_00000_01000 # C4 / B4
    bits |= @wood_man   ? 0b00000_00000_00000_10000 : 0b00000_00100_00000_00000 # B5 / D3
    bits |= @crash_man  ? 0b00010_:00000_00000_00000 : 0b00000_00000_10000_00000 # E2 / C5
    bits |= @flash_man  ? 0b01000_00000_00000_00000 : 0b00000_00000_00001_00000 # E4 / C1
    bits |= @metal_man  ? 0b00001_00000_00000_00000 : 0b10000_00000_00000_00000 # E1 / E5
    bits |= @heat_man   ? 0b00000_10000_00000_00000 : 0b00000_00000_00000_00010 # D5 / B2

    manual bit addition........... bit OR |
    bits |= @bubble_man ? 00000_00001_00000_00000 # C3 / D1
    bits |= @air_man    ? 00100_00000_00000_00000 # D2 / E3
    ------------------------------------------------
                          00100 00001 00000 00000
*/

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

int bitSet(unsigned int bits, const unsigned byte pos) {

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

    printf("etanks 0 (alone): %i\n", etanks(0));
    printf("before etanks: %i\n", bits);
    bits = bits | (etanks(0));
    /*
        etanks: 5 bits
            00001 // 0 etanks
            00010 // 1 etank
            00100 // 2 etanks
            01000 // 3 etanks
            10000 // 4 etanks
    */
    printf("%i\n", bits);

    decode(bits);

    /*
    for (int i = 0; i < 5; i++) {
        printf("etanks %i: %i\n", i, etanks(i));
    }
    */
    return 0;
}
