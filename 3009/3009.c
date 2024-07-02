#include <stdio.h>

int main()
{
    int coordinates[3][2]; // 3개의 입력 중 1번만 나온 x, y를 출력하면 됨

    // 미리 x, y count를 1씩 증가시켜줌
    scanf("%d %d", &coordinates[0][0], &coordinates[0][1]);
    int x_count = 1;
    int y_count = 1;

    scanf("%d %d", &coordinates[1][0], &coordinates[1][1]);
    if (coordinates[1][0] == coordinates[0][0]) // 첫번째 입력과 같은 경우
        x_count++;

    if (coordinates[1][1] == coordinates[0][1]) // 첫번째 입력과 같은 경우
        y_count++;

    scanf("%d %d", &coordinates[2][0], &coordinates[2][1]);
    if (x_count == 2) // x가 이미 2개가 나온 경우 바로 현재 입력을 출력하면 됨 (현재 입력은 이제 처음 1번만 나왔기 때문)
        printf("%d ", coordinates[2][0]);
    else
        // x가 이제서야 2개 나온 경우 첫번째 입력과 두번째 입력을 비교해서 현재 입력과 다른 x를 출력하면 됨
        printf("%d ", coordinates[2][0] == coordinates[1][0] ? coordinates[0][0] : coordinates[1][0]); // 같으면 첫번째, 다르면 두번째 입력을 출력

    if (y_count == 2) // y가 이미 2개가 나온 경우 바로 현재 입력을 출력하면 됨 (현재 입력은 이제 처음 1번만 나왔기 때문)
        printf("%d", coordinates[2][1]);
    else
        // y가 이제서야 2개 나온 경우 첫번째 입력과 두번째 입력을 비교해서 현재 입력과 다른 y를 출력하면 됨
        printf("%d", coordinates[2][1] == coordinates[1][1] ? coordinates[0][1] : coordinates[1][1]); // 같으면 첫번째, 다르면 두번째 입력을 출력
}