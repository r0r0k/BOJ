#include <stdio.h>

int main()
{
    int coordinates[3][2]; // 3개의 입력 중 1번만 나온 x, y를 출력하면 됨

    scanf("%d %d", &coordinates[0][0], &coordinates[0][1]);
    scanf("%d %d", &coordinates[1][0], &coordinates[1][1]);
    scanf("%d %d", &coordinates[2][0], &coordinates[2][1]);

    int x, y;

    if (coordinates[0][0] == coordinates[1][0])
        x = coordinates[2][0];
    else if (coordinates[1][0] == coordinates[2][0])
        x = coordinates[0][0];
    else if (coordinates[0][0] == coordinates[2][0])
        x = coordinates[1][0];

    if (coordinates[0][1] == coordinates[1][1])
        y = coordinates[2][1];
    else if (coordinates[1][1] == coordinates[2][1])
        y = coordinates[0][1];
    else if (coordinates[0][1] == coordinates[2][1])
        y = coordinates[1][1];

    printf("%d %d", x, y);
}