#include <stdio.h>

int main()
{
    int climb;
    int slip;
    int height;
    int now_height = 0;
    int required_day = 0; // 올라가는데 필요한 날짜 수

    scanf("%d %d %d", &climb, &slip, &height);

    // 이렇게 하면 정답은 맞지만 시간 초과
    while (1)
    {
        required_day++;
        now_height += climb;
        if (now_height >= height) // 만약 현재 올라간 높이가 나무 높이보다 크거나 같으면 종료
            break;
        else // 아닌 경우 slip으로 미끄러져야함
            now_height -= slip;
    }

    printf("%d", required_day);
}