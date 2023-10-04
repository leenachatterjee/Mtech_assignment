#include <stdio.h>

// Function to add two BCD numbers
int addBCD(int num1, int num2) {
    int carry = 0;
    int result = 0;
    int base = 1;

    while (num1 > 0 || num2 > 0 || carry > 0) {
        int digit1 = num1 % 10;
        int digit2 = num2 % 10;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum %= 10;

        result += sum * base;
        base *= 10;

        num1 /= 10;
        num2 /= 10;
    }

    return result;
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

        result = addBCD(num1, num2);

        printf("%d (", num1);
        int mask = 1000;
        while (mask > 0) {
            if (num1 / mask > 0) {
                printf("1");
                num1 %= mask;
            } else {
                printf("0");
            }
            mask /= 10;
        }

        printf(") + %d (", num2);
        mask = 1000;
        while (mask > 0) {
            if (num2 / mask > 0) {
                printf("1");
                num2 %= mask;
            } else {
                printf("0");
            }
            mask /= 10;
        }

        printf(") = %d (", result);
        mask = 1000;
        while (mask > 0) {
            if (result / mask > 0) {
                printf("1");
                result %= mask;
            } else {
                printf("0");
            }
            mask /= 10;
        }

        printf(")\n");
    }

    return 0;
}
