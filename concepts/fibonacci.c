#include <stdio.h>

int main(void)
{
    int n;
    int first = 0;
    int second = 1;
    int next;

    printf("=====================================\n");
    printf("      Fibonacci Series Generator\n");
    printf("=====================================\n");

    /* Get user input */
    printf("Enter the number of Fibonacci terms: ");
    scanf("%d", &n);

    /* Validate input */
    if (n <= 0)
    {
        printf("\nError: Please enter a positive integer.\n");
        return 1;
    }

    printf("\nFirst %d Fibonacci Terms:\n", n);

    /* Generate Fibonacci Series */
    for (int i = 1; i <= n; i++)
    {
        printf("Term %2d : %d\n", i, first);

        next = first + second;
        first = second;
        second = next;
    }

    printf("\nProgram executed successfully.\n");

    return 0;
}
