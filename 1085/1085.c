#include <stdio.h>

int main()
{
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    int x_dist = w - x >= x ? x : w - x; // x_dist의 최솟값
    int y_dist = h - y >= y ? y : h - y; // y_dist의 최솟값

    printf("%d", x_dist >= y_dist ? y_dist : x_dist); // 둘 중 작은 값을 출력

    // int min = x;
    // if (min > y)
    //     min = y;
    // if (min > w - x)
    //     min = w - x;
    // if (min > h - y)
    //     min = h - y;

    // printf("%d", min);
}