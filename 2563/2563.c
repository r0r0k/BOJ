#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int x, y;

    // 좌표를 통해 중복되는 영역을 표시, element가 n이면 n개의 색종이가 위치(=n-1번 중복)
    // x,y를 따로 두면 x,y가 겹쳐서 중복되는 것을 체크 불가 (x만 겹치고 y는 안겹칠 수 있기 때문)
    int dup[100][100] = {
        0,
    };

    scanf("%d", &n);

    // 겹치지 않았을 때의 전체 색종이 넓이의 합
    int area = n * 100;

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        for (int j = x; j < x + 10; j++)
            for (int k = y; k < y + 10; k++)
                dup[j][k]++; // 색종이가 차지하는 element에 +1을 해줌
    }

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (dup[i][j] > 1) // 색종이가 차지하는 element가 1보다 큰 경우 중복
                area -= dup[i][j] - 1;
    // (element -1)만큼 빼주면 해당 영역이 중복된 횟수만큼 뺄 수 있음
    // 예를 들어 dup[i][j] == 3인 경우 3개의 색종이가 같은 영역에 위치하므로 area에서 해당 영역을 2번 빼줘야함

    printf("%d", area);
}