#include <stdio.h>

int main(void)
{
    int number, originalNumber, remainder;
    int digitCount = 0;
    int sum = 0;

    printf("=====================================\n");
    printf("      Armstrong Number Checker\n");
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

    /* Count the number of digits */
    while (originalNumber != 0)
    {
        digitCount++;
        originalNumber /= 10;
    }

    /* Handle the case when the number is 0 */
    if (number == 0)
    {
        digitCount = 1;
    }

    originalNumber = number;

    /* Calculate the Armstrong sum */
    while (originalNumber != 0)
    {
        int power = 1;
        remainder = originalNumber % 10;

        for (int i = 0; i < digitCount; i++)
        {
            power *= remainder;
        }

        sum += power;
        originalNumber /= 10;
    }

    /* Handle the case when the number is 0 */
    if (number == 0)
    {
        sum = 0;
    }

    /* Display result */
    if (sum == number)
    {
        printf("\n%d is an Armstrong Number.\n", number);
    }
    else
    {
        printf("\n%d is Not an Armstrong Number.\n", number);
    }

    printf("\nProgram executed successfully.\n");

    return 0;
}
