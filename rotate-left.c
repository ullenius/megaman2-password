#include <stdio.h>

#define WORD_SIZE 20

unsigned int rotateLeft(unsigned int bits) {

    // left rotation of bits by 2 steps. 
    // 20 bit word size

    unsigned int leftmost = (bits >> (WORD_SIZE - 2));
    printf("leftmost: %i\n", leftmost); 

    unsigned int rightmost = (bits << 2);
    unsigned int mask = 0xFFFFF; // 20 bits set
    // we only keep the rightmost 20 bits
    rightmost = rightmost & mask;

    unsigned int result = leftmost | rightmost;

    // apply the rotated bits to the original
    // first we clear the affected word
    unsigned clearLastBits = bits & 0xFFF00000;
    // then we OR using our result (rotated word)
    result = result | clearLastBits;

    printf("result: %i\n", result);
}

int main() {

    printf("sizeof int: %i\n", sizeof(int));
    //unsigned int foo = 0xFFFF; // 0000 0000 0000 0000 1111 1111 1111 1111
    unsigned int foo = 0x80001; // 20th bit set
    rotateLeft(foo);

    return 0;
}
