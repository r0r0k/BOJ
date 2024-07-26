#include <iostream>
using namespace std;

int n;
long dp[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    // 초기값 정하기
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    // 점화식 찾기
    for (int i = 6; i <= 100; i++)
    {
        if (2 <= i % 12 && i % 12 <= 4)
            dp[i] = dp[i - 1];
        dp[i] = dp[i - 5] + dp[i - 1];
    }

    int input;
    while (n--)
    {
        cin >> input;
        cout << dp[input] << '\n';
    }

    return 0;
}