#include <stdio.h>

// Function to print the binary representation of a number
void printBinary(unsigned char num) {
    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }

    for (int i = sizeof(unsigned char) * 8 - 1; i >= 0; i--) {
        printf("%d", (num & (1 << i)) ? 1 : 0);
    }

    printf("\n");
}

// Function to check if a specific bit is set and set all bits to the right
int checkAndSetBitsToRight( unsigned char value ) {

    for (int i = sizeof(unsigned char) * 8 - 1; i >= 0; i--) 
    {
        if ( value & (1 << i) )
        {
            return (( value ) | ((1 << i) - 1));
        }
    }
}
int main() {
    unsigned char number = 0x04;
    // Print the binary representation of the original number
    printf("Original ");
    printBinary(number);

    // Check if the bit is set and set bits to the right
    int result = checkAndSetBitsToRight(number);

    // Print the binary representation of the modified number
    printf("Modified ");
    printBinary(result);

    return 0;
}
