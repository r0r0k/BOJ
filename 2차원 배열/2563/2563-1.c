#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int x, y;

    int dup[100][100] = {
        0,
    };

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        for (int j = x; j < x + 10; j++)
            for (int k = y; k < y + 10; k++)
                dup[j][k] = 1; // 색종이가 차지하는 면적에 1을 대입(겹쳐도 1으로 되어서 상관X)
    }

    int area = 0;

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (dup[i][j] == 1) // 색종이가 차지하는 element가 1보다 큰 경우 중복
                area++;

    printf("%d", area);
}