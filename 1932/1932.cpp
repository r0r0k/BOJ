#include <iostream>
using namespace std;

int n;
int dp[501][501]; // dp[i][j]는 꼭대기를 기준으로, i번째 삼각형에서 j번째 수를 선택했을 때의 최댓값

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> dp[i][j]; // 정수 삼각형 입력

    // 1-index 이므로, `i-1`에서 segfault가 발생하지 않음
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]); // 점화식 찾기, i - 1 줄의 왼쪽 대각선(j-1)과 오른쪽 대각선(j) 중 큰 것을 선택

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dp[n][i]); // 마지막 열에서 최댓값을 선택

    cout << res;
    return 0;
}