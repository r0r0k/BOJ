#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001]; // 입력 받은 수열을 저장하는 배열 : n <= 1000, 1-index
int dp[1001];  // 테이블 정의하기 : i번째 수를 수열의 끝으로 하는 증가하는 부분 수열의 길이
int res_max;   // 현재까지 증가하는 부분 수열의 길이의 최댓값

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i] = 1; // 초기값 설정 : 모든 수열은 자기 자신의 길이가 1이기 때문
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        res_max = max(res_max, dp[i]);
    }

    cout << res_max;

    // sort(dp, dp + n);
    // cout << dp[n];

    return 0;
}