#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int number;
    int notation;

    scanf("%d %d", &number, &notation);

    int size = 0; // output의 자리수
    char output[30] = {
        0,
    }; // 2745번처럼 최소인 2진수인 경우 10억 이하일 때 최대 자리수가 29이기 때문에 출력으로 가능한 자릿수가 총 29개

    int pow_;     // B진수의 자리가 존재하는지 계산하기 위한 변수
    int quotient; // B진수의 자리에 들어갈 값을 계산하기 위한 몫
    int flag = 0; // 처음 나온 자리 이후에는 '0'을 붙이기 위해

    int limit = 0;
    while (pow(notation, limit) <= 1e9) // 계산 범위가 10억 이내이므로 아래처럼 29제곱부터 할 필요 없음
        limit++;

    for (int i = limit; i >= 0; i--) // 최소인 2진수에서 29제곱부터 가능하므로 높은 제곱부터 차례로 해줘야함 (낮은 제곱부터 하면 결정 불가)
    {
        // if (pow(notation, i) <= 1e9) // 범위가 36^29는 아예 계산 범위를 넘어서서 계산이 안됨
        //     pow_ = pow(notation, i);
        // else
        //     continue;

        pow_ = pow(notation, i);
        if (number - pow_ >= 0) // B진수의 해당 자리가 존재하는지 계산 ex) i = 29, B = 2일 때, 2진수의 29번째 자리수가 존재하는지 계산
        {
            if (!flag) // 처음 자릿수가 나오기 전에는 '0'을 붙이면 안되므로, 처음 자릿수가 나왔을 때 flag를 1으로 바꿔줌
                flag++;

            quotient = number / pow_;
            if (quotient >= 0 && quotient <= 9)
                output[size] = quotient + '0'; // char로 변환 필요

            else // 'A' ~ 'Z'
                output[size] = quotient + 55;

            number -= (pow_ * quotient);
            size++;
        }
        else if (flag) // number - pow_ < 0 (해당 자릿수 존재 X) and flag == true 인 경우
        {
            output[size] = '0';
            size++;
        }

        if (number == 0) // number가 0이 되면 더이상 진행할 필요 X
            break;
        else if (number < 0)
        {
            printf("Error\n");
            exit(0);
        }
    }

    for (int i = 0; i < size; i++)
        printf("%c", output[i]);
    // printf("%s", output);
}