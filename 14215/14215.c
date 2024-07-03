#include <stdio.h>

int main()
{
    int sides[3];
    scanf("%d %d %d", &sides[0], &sides[1], &sides[2]);

    int hypotenuse = sides[0];
    int hypotenuse_index = 0;

    if (sides[1] > hypotenuse)
    {
        hypotenuse = sides[1];
        hypotenuse_index = 1;
    }

    if (sides[2] > hypotenuse)
    {
        hypotenuse = sides[2];
        hypotenuse_index = 2;
    }

    hypotenuse += sides[hypotenuse_index]; // 아래에서 삼각형 조건을 계산하기 위해
    for (int i = 0; i < 3; i++)
        hypotenuse -= sides[i];

    if (hypotenuse < 0)
        printf("%d", sides[0] + sides[1] + sides[2]);

    else
    {
        int new_round = -sides[hypotenuse_index]; // 새로운 둘레를 계산하기 위해 변수 선언 후 미리 빗변을 빼줌
        for (int i = 0; i < 3; i++)
            new_round += sides[i];

        printf("%d", 2 * new_round - 1); // 반복문 결과 new_round에는 빗변을 제외한 두 변의 합이 나오므로 2배 후 -1을 해주면 최대 둘레의 삼각형이 나옴
    }
}
