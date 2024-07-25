#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int *dp = new int[n + 1]; // index를 1부터 사용하기 위해

    dp[1] = 0; // 초기값 설정
    for (int i = 1; i <= n - 1; i++)
    {
        if (dp[i + 1] == 0 || dp[i + 1] > dp[i] + 1)
            dp[i + 1] = dp[i] + 1;

        if (i * 2 <= n && (dp[i * 2] == 0 || dp[i * 2] > dp[i] + 1))
            dp[i * 2] = dp[i] + 1;

        if (i * 3 <= n && (dp[i * 3] == 0 || dp[i * 3] > dp[i] + 1))
            dp[i * 3] = dp[i] + 1;
    }

    cout << dp[n];

    delete[] dp;
    return 0;
}