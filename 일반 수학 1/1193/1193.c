#include <stdio.h>

// 구간의 길이, 시작점, 끝점, 구간의 분수 합, 구간의 분수 분자, 분모 보기
// 여기선 구간의 시작점, 분자, 분모로 풀었음

int main()
{
    int n;
    scanf("%d", &n);

    int start_range = 1; // 같은 합을 나타내는 구간의 시작점
    int range_th = 1;    // 몇 번째 구간인지 : 분자 or 분모의 최댓값을 결정

    while (!(n >= start_range && n < start_range + range_th))
    {
        start_range += range_th; // 구간 이동
        range_th++;
    }

    int th = n - start_range; // 구간 내에서 몇번째 값인지 (0번째 부터 시작)

    if (range_th % 2 != 0) // 홀수 번째 구간인 경우
    {
        printf("%d", range_th - th);
        printf("/");
        printf("%d", th + 1); // th는 0부터 시작하므로
    }

    else if (range_th % 2 == 0) // 짝수 번째 구간인 경우
    {
        printf("%d", th + 1); // th는 0부터 시작하므로
        printf("/");
        printf("%d", range_th - th);
    }
}