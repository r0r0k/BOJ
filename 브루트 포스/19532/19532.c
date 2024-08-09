#include <stdio.h>

int main()
{
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    int solution[2]; // x, y

    for (int i = -999; i <= 999; i++)
        for (int j = -999; j <= 999; j++)
        {
            if (a * i + b * j == c && d * i + e * j == f)
            {
                printf("%d %d", i, j);
                return 0;
                // 다중 for문 탈출하려면, break 하나로는 불가
                // 1. return
                // 2. flag 변수 설정을 통해 outer for문에서 flag 체크 후 한번 더 break
            }
        }
}