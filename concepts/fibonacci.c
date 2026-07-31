#include <stdio.h>

int main(void)
{
    int number;
    int isPrime = 1;

    printf("=====================================\n");
    printf("       Prime Number Checker\n");
    printf("=====================================\n");

    /* Get input from user */
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    /* Validate input */
    if (number <= 1)
    {
        printf("\n%d is not a prime number.\n", number);
        return 0;
    }

    /* Check for factors */
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            isPrime = 0;
            break;
        }
    }

    /* Display result */
    if (isPrime)
        printf("\n%d is a Prime Number.\n", number);
    else
        printf("\n%d is Not a Prime Number.\n", number);

    printf("\nProgram executed successfully.\n");

    return 0;
}
