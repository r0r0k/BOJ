#include <stdio.h>

int main()
{
    int count;
    scanf("%d", &count);

    int number;
    int prime_cnt = 0;

    int factor_cnt;
    while (count--)
    {
        scanf("%d", &number);
        factor_cnt = 0;
        for (int i = 1; i <= number; i++)
            if (number % i == 0)
                factor_cnt++;

        if (factor_cnt == 2) // 소수는 약수 개수가 2개이므로
            prime_cnt++;
    }
    printf("%d", prime_cnt);
}