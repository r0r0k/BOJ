#include <stdio.h>
#include <string.h>

int main()
{
    char number[30]; // 최소인 2진수에서 2^30이 처음으로 10억보다 커지므로, 최대 가능한 2진수의 자릿수는 29이기 때문
    scanf("%s", number);

    int notation; // 몇진법인지
    scanf("%d", &notation);

    int power = 0; // 자릿수에 따른 10진법 계산을 위해
    int result = 0;
    int size = strlen(number);

    while (--size >= 0) // 처음 입력은 배열의 끝에 있으므로 --size를 해주고 index 0까지 가야하므로 >= 0 조건 추가
    {
        int decimal; // input으로 받은 진법의 수를 10 진수의 각 자리 수로 변형할 변수

        if (number[size] >= '0' && number[size] <= '9')
            decimal = number[size] - '0';
        else // 알파벳인 경우
            decimal = number[size] - 'A' + 10;

        int k = power; // 반복문 iterator
        // for (int i = 0; i < power; i++)
        while (k--) // 항상 0이 아닌 양수나 음수는 true이므로 잘 생각하기
            decimal *= notation;

        result += decimal;
        power++;
    }
    printf("%d", result);
}