#include <stdio.h>

int main()
{
    int number;
    int factor_sum; // 약수의 합
    while (1)
    {
        scanf("%d", &number);
        if (number == -1)
            break;

        factor_sum = 0;
        for (int i = 1; i < number; i++) // number는 i에서 제외
            if (number % i == 0)         // 약수인 경우
                factor_sum += i;         // 완전수인지 먼저 체크하기 위해 factor_sum을 구해줌

        if (factor_sum == number) // 완전수인 경우
        {
            factor_sum = 0; // 계산을 위해 초기화
            printf("%d = ", number);
            for (int i = 1; i < number; i++) // 다시 약수를 찾으며 출력
            {
                if (number % i == 0)
                {
                    printf("%d ", i);
                    factor_sum += i;
                    if (factor_sum != number) // 아직 완전 수가 만들어지지 않은 경우
                        printf("+ ");
                    else // 완전 수가 만들어진 경우
                    {
                        printf("\n");
                        break;
                    }
                }
            }
        }
        else // 완전수가 아닌 경우
            printf("%d is NOT perfect.\n", number);
    }
}