#include <stdio.h>

int main()
{
    int climb;
    int slip;
    int height;
    int day_sum;          // 하루에 올라가는 높이의 총합 (= climb - slip)
    int required_day = 1; // 가장 마지막 날을 미리 더해줌 (아래에서 height에서 climb를 빼주기 때문)

    scanf("%d %d %d", &climb, &slip, &height);

    height -= climb; // 마지막 날에는 climb만 하므로 미리 빼줌
    day_sum = climb - slip;

    if (height % day_sum != 0) // 나무 높이를 day_sum으로 나눴을 때, 나머지가 존재하면 몫에서 1을 더해줘야함
        required_day += height / day_sum + 1;

    else // 나누어 떨어지는 경우 그냥 몫만더해주면 됨
        required_day += height / day_sum;

    printf("%d", required_day);
}