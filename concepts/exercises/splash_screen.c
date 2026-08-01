/*
 * palindrome_number.c
 *
 * Checks whether an integer reads the same forwards and backwards
 * (e.g. 121, 1331). Classic beginner exercise for practicing loops,
 * the modulo operator, and integer manipulation.
 */

#include <stdio.h>

int main(void)
{
    int number;
    int originalNumber;
    int remainder;
    int reversedNumber = 0;

    printf("====================================\n");
    printf("      Palindrome Number Checker\n");
    printf("====================================\n\n");

    /* Get input from user */
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    /* Validate input */
    if (number < 0) {
        printf("Negative numbers are not supported.\n");
        return 1;
    }

    originalNumber = number;

    /* Reverse the number digit by digit */
    while (number != 0) {
        remainder = number % 10;
        reversedNumber = (reversedNumber * 10) + remainder;
        number /= 10;
    }

    /* Compare original with reversed */
    if (originalNumber == reversedNumber) {
        printf("%d is a palindrome.\n", originalNumber);
    } else {
        printf("%d is NOT a palindrome.\n", originalNumber);
    }

    return 0;
}
