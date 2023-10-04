#include <stdio.h>

// Function to subtract two BCD numbers
int subtractBCD(int num1, int num2) {
    int carry = 0;
    int result = 0;
    int base = 1;

    while (num1 > 0 || num2 > 0) {
        int digit1 = num1 % 10;
        int digit2 = num2 % 10;

        int sub = digit1 - digit2 - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result += sub * base;
        base *= 10;

        num1 /= 10;
        num2 /= 10;
    }

    return result;
}

// Function to print the binary representation of a number
void printBinary(int num) {
    int binary[32];
    int i = 0;

    while (num > 0) {
        binary[i++] = num % 2;
        num /= 2;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main() {
    int numCases;
    printf("Number of test cases: ");
    scanf("%d", &numCases);

    while (numCases--) {
        int num1, num2, result;
        printf("First number: ");
        scanf("%d", &num1);
        printf("Second number: ");
        scanf("%d", &num2);

        result = subtractBCD(num1, num2);

        printf("%d (", num1);
        printBinary(num1);
        printf(") - %d (", num1);
        printBinary(num1);
        printf(") = %d (", result);
        printBinary(result);
        printf(")\n");
    }

    return 0;
}
