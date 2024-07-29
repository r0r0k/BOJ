#include <iostream>
using namespace std;

int n;
int arr[1001];
int inc_dp[1001]; // i번째 수가 수열의 끝이 되는 증가하는 부분 수열
int dec_dp[1001]; // i번째 수가 수열의 시작이 되는 감소하는 부분 수열
int res_max;      // 가장 긴 바이토닉 부분 수열의 길이

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        // 초기값 설정
        inc_dp[i] = 1;
        dec_dp[i] = 1;
    }

    // 증가하는 부분 수열 구하기
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (arr[i] > arr[j])
                inc_dp[i] = max(inc_dp[j] + 1, inc_dp[i]);

    // 감소하는 부분 수열 구하기 (증가하는 부분 순열과 반대 방향으로 구해야 이전 테이블의 정보를 누적해서 알 수 있음)
    for (int i = n; i >= 1; i--)
        for (int j = n; j >= i; j--)
            if (arr[i] > arr[j])
                dec_dp[i] = max(dec_dp[j] + 1, dec_dp[i]);

    // 가장 긴 바이토닉 부분 수열의 길이를 구하기 위해서는 i에서 inc_dp와 dec_dp의 합에서 중복되는 i를 생각하여 1을 뺀 값의 최댓값을 찾아주면 됨
    for (int i = 1; i <= n; i++)
        res_max = max(res_max, inc_dp[i] + dec_dp[i] - 1);

    cout << res_max;
    return 0;
}