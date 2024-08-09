#include <stdio.h>

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int prime_cnt = 0;       // prime number가 존재하는지 파악하기 위해
    int prime_sum = 0;       // prime number의 합
    int prime_min;           // prime number의 최솟값
    int prime_min_found = 0; // prime number를 찾았으면 더이상 업데이트하지 않기 위해

    int factor_cnt; // prime number인지 확인하기 위한 약수 개수

    for (int i = n1; i <= n2; i++) // n1~n2까지 prime number인지 확인
    {
        factor_cnt = 0;
        for (int j = 1; j <= i; j++)
            if (i % j == 0)
                factor_cnt++;

        if (factor_cnt == 2) // i가 prime number인 경우
        {
            prime_cnt++;
            prime_sum += i;
            if (!prime_min_found) // 처음 찾은 prime_number인 경우 해당 조건을 만족하므로 prime_min 값을 현재 i로 update
            {
                prime_min = i;
                prime_min_found = 1; // prime_min을 찾았기 때문에 found를 1로 update
            }
        }
    }

    if (prime_cnt == 0)
        printf("-1");
    else
        printf("%d\n%d", prime_sum, prime_min);
}