#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // 테이블 정의 : dp[i][j]는 j만큼 연속적으로 계단을 올랐을 때, i번째 계단에 대한 점수 최댓값
    // 계단 수는 300 이하에서 1-index를 쓰면서 연속으로 오른 계단의 수는 1,2가 가능하므로 [301][3]의 크기를 가짐
    int dp[301][3] = {0}; // 전역변수는 선언만 해도 0으로 초기화 되지만, 지역 변수는 초기화해줘야함

    // 각 계단의 점수를 저장하는 배열
    int score[301];

    for (int i = 1; i <= n; i++)
        cin >> score[i];

    // 초기값 설정
    dp[1][1] = score[1];
    dp[2][1] = score[2];
    dp[2][2] = score[1] + score[2];

    for (int i = 3; i <= n; i++)
    {
        // 지금까지 1번 계단을 연속적으로 올라간 경우는 두 계단을 뛰어 넘어간 것이므로, i - 2 번째의 최댓값중 더 큰 값에 score를 더하면 됨
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];
        // 지금까지 2번 계단을 연속적으로 올라간 경우는 바로 이전 계단에서 한 계단을 연속적으로 올라간 경우
        dp[i][2] = dp[i - 1][1] + score[i];
    }

    cout << max(dp[n][1], dp[n][2]);

    return 0;
}