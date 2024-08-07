#include <iostream>
using namespace std;

int n;
int dp[12]; // 테이블 정의하기 : dp[i]는 `i`를 만드는데 필요한 방법의 수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size;
    cin >> size;

    // 초기값 정하기
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    while (size--)
    {
        cin >> n;

        for (int i = 4; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

        cout << dp[n] << '\n';
    }

    return 0;
}