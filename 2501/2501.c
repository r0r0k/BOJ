#include <stdio.h>

int main()
{
    int number;
    int factor_th;

    scanf("%d %d", &number, &factor_th);
    int factor_cnt = 0;

    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
            factor_cnt++;

        if (factor_cnt == factor_th)
        {
            printf("%d", i);
            return 0;
        }
    }

    printf("0");
}