#include <iostream>
using namespace std;

int n;
long dp[1001]; // 테이블 정의하기 : dp[i] 는 2 x i 직사각형을 타일로 채우는 경우의 수 (n <= 1000, 1-index)

int topdown(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (dp[n] != 0)
        return dp[n];

    return dp[n] = (topdown(n - 1) + topdown(n - 2)) % 10007;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    // 초기값 정하기
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007; // 점화식 찾기

    cout << dp[n];

    // cout << topdown(n);
    return 0;
}