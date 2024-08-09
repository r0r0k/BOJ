#include <iostream>
using namespace std;

int n;
int dp[1001][3]; // 테이블 정하기 : dp[i][j] 는 i번째 집에 j 색상을 칠했을 때 비용의 최솟값 (j는 0부터 2까지 차례대로 R, G, B를 나타냄)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            cin >> dp[i][j]; // 각 집을 j 색상으로 칠하는 비용을 미리 입력 받아줌

    // 초기값 정하기 : dp[0][j] 는 이미 0으로 초기화 되있기 때문에 초기값을 설정할 필요가 없음

    for (int i = 1; i <= n; i++)
    {
        // 점화식 찾기 : dp[i][j]는 i - 1 집에서 j 색상과 다른 색상 중 최솟값을 더해주면 됨
        dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);

    return 0;
}