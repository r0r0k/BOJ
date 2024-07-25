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
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1; // 초기값이 0이므로, 먼저 1을 뺀 연산부터 업데이트해줘야함

        if (i % 2 == 0) // 2으로 나누어 떨어지면, 1을 뺀 연산과 최솟값 비교 후 업데이트
            dp[i] = min(dp[i], dp[i / 2] + 1);

        if (i % 3 == 0) // 3으로 나누어 떨어지면, 위의 결과 값과 최솟값 비교 후 업데이트
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    cout << dp[n];

    delete[] dp;
    return 0;
}