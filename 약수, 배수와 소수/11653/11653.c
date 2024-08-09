#include <stdio.h>

int main()
{
    int number;
    scanf("%d", &number);

    for (int i = 2; i <= number; i++) // 소인수 분해는 2부터 시작
    {
        while (number % i == 0) // 같은 i에 대해서 number를 한번 더 나눴을 때 나머지가 0이라면 계속 진행 (약수가 아닌 소인수 분해이므로)
        {
            printf("%d\n", i);
            number /= i;
            if (number == 1)
                break;
        }
    }
}