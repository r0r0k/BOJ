#include <stdio.h>

int main()
{
    int sides[3];         // 변
    int hypotenuse;       // 빗변
    int hypotenuse_index; // 빗변을 나타내는 index (이거 안쓰고 hypotenuse를 한번 더 더해줘서 계산에서 빗변 index를 제외하지 않는 방법 사용 가능)

    while (1)
    {
        scanf("%d %d %d", &sides[0], &sides[1], &sides[2]);
        hypotenuse = sides[0];
        hypotenuse_index = 0;

        if (!sides[0] || !sides[1] || !sides[2]) // 세 변 중 하나라도 0이 존재하는 경우 break;
            break;

        // 빗변을 구하기 위해
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

        for (int i = 0; i < 3; i++)
        {
            if (i == hypotenuse_index) // 빗변의 경우 계산에서 제외
                continue;
            hypotenuse -= sides[i];
        }

        if (hypotenuse >= 0) // 삼각형의 조건을 만족하지 않는 경우
            printf("Invalid\n");

        else if (sides[0] == sides[1] || sides[1] == sides[2] || sides[0] == sides[2]) // 이등변 삼각형인 경우
        {
            if (sides[0] == sides[1] && sides[1] == sides[2]) // 세 변이 같으면
                printf("Equilateral\n");
            else
                printf("Isosceles\n");
        }

        else // 이등변 삼각형이 아닌 경우
            printf("Scalene\n");
    }
}