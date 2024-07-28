#include <iostream>
using namespace std;

int n;
int dp[501][502]; // dp[i][j]는 꼭대기를 기준으로, i번째 삼각형에서 j번째 수를 선택했을 때의 최댓값, 1-index와 (j+1) index의 segfault를 방지하기 위해 [501][502]로 설정

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> dp[i][j]; // 정수 삼각형 입력

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j + 1]);

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dp[n][i]);

    cout << res;
    return 0;
}