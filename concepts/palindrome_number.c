#include <stdio.h>

int main(void)
{
    int number;
    int originalNumber;
    int remainder;
    int reversedNumber = 0;

    printf("=====================================\n");
    printf("      Palindrome Number Checker\n");
    printf("=====================================\n");

    /* Get input from user */
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    /* Validate input */
    if (number < 0)
    {
        printf("\nError: Please enter a positive integer.\n");
        return 1;
    }

    originalNumber = number;

    /* Reverse the number */
    while (number != 0)
    {
        remainder = number % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        number = number / 10;
    }

    /* Check whether the number is a palindrome */
    if (originalNumber == reversedNumber)
    {
        printf("\n%d is a Palindrome Number.\n", originalNumber);
    }
    else
    {
        printf("\n%d is Not a Palindrome Number.\n", originalNumber);
    }

    printf("\nProgram executed successfully.\n");

    return 0;
}
