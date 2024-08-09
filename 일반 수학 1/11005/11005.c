#include <stdio.h>

int main()
{
    int number;
    int notation;

    char output[30] = {
        0,
    };

    scanf("%d %d", &number, &notation);

    int size = 0;
    while (number > 0)
    {
        output[size] = number % notation; // 나머지가 자리수 결정
        if (output[size] >= 0 && output[size] <= 9)
            output[size] += '0';
        else
            output[size] += 55;
        size++;
        number /= notation; // 몫을 구해주면 그 앞에 B진수의 B가 곱해져 있는 것이므로 앞으로 계속 나아가짐
    }
    while (--size >= 0)
        printf("%c", output[size]);
}