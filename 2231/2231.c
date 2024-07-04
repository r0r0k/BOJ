#include <stdio.h>

int main()
{
    int number; // 자연수 N
    scanf("%d", &number);

    int constructor_found = 0; // number의 constructor가 찾아졌는지 확인하기 위함
    int disassemble;           // 분해합 ex) 256(=245+2+4+5)
    int constructor;           // 생성자 ex) 245
    int cmp;                   // constructor 계산을 위한 변수

    for (int i = 1; i <= 1000000; i++) // 1 ~ 1,000,000 까지 number(자연수 N)의 constructor가 존재하는지 확인
    {
        disassemble = i;
        cmp = i;         // iterator인 i값 자체를 업데이트 하지 않으면서 카피해서 비교하기 위해
        while (cmp != 0) // 각 자리의 숫자를 전부 더하는 반복문
        {
            disassemble += cmp % 10;
            cmp /= 10;
        }

        if (disassemble == number) // 계산한
        {
            constructor_found = 1;
            constructor = i;
            break;
        }
    }

    if (constructor_found)
        printf("%d", constructor);
    else
        printf("0");
}