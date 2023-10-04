#include <stdio.h>

// Function to check if a decimal number can be represented in BCD
int canRepresentInBCD(int decimal, int bitsAvailable) {
    // Calculate the maximum decimal number that can be represented with the given bits
    int maxDecimal = (1 << bitsAvailable) - 1;
    
    return decimal <= maxDecimal;
}

// Function to convert a decimal number to its BCD representation
void decimalToBCD(int decimal) {
    int bcd = 0;
    int multiplier = 1;

    while (decimal > 0) {
        int digit = decimal % 10;
        int binaryDigit = 0;

        // Convert the decimal digit to its binary representation
        while (digit > 0) {
            binaryDigit = (binaryDigit << 1) | (digit & 1);
            digit >>= 1;
        }

        // Place the binary representation in the BCD
        bcd |= (binaryDigit << (4 * multiplier));
        multiplier++;

        decimal /= 10;
    }

    printf("BCD equivalent: ");
    for (int i = 15; i >= 0; i--) {
        if (i % 4 == 3) {
            printf(" "); // Add space for formatting
        }
        printf("%d", (bcd >> i) & 1);
    }
    printf("\n");
}

int main() {
    int numCases;
    printf("Number of test cases: ");
    scanf("%d", &numCases);

    while (numCases--) {
        int bitsAvailable, decimal;
        printf("Bits available? : ");
        scanf("%d", &bitsAvailable);
        printf("Decimal Number: ");
        scanf("%d", &decimal);

        if (canRepresentInBCD(decimal, bitsAvailable)) {
            decimalToBCD(decimal);
        } else {
            printf("BCD equivalent: cannot be represented\n");
        }
    }

    return 0;
}
