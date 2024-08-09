#include <stdio.h>

int main()
{
    int dividend, divisor, number;
    scanf("%d %d %d", &dividend, &divisor, &number);

    for (int i = 0; i < number; i++)
    {
        dividend = dividend % divisor;
        dividend *= 10;
    }

    int result = dividend / divisor;
    printf("%d", result);
}