#include <iostream>
using namespace std;

int n;
int arr[100001];     // 입력값을 저장하는 배열
int cum_sum[100001]; // 현재까지의 누적합을 저장하는 배열 (누적합이 음수가 되는 경우 다음 누적합은 새로운 arr 부터 시작)
int sum_max;         // 현재 연속합의 최댓값

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    // 초기값 정하기 : 사실 생각해보면 1-index에서는 (i - 1)이 점화식 항에 포함된 경우 딱히 안해줘도 되긴함ㄴ
    cum_sum[1] = arr[1];
    sum_max = arr[1];

    for (int i = 2; i <= n; i++)
    {
        cum_sum[i] = max(cum_sum[i - 1] + arr[i], arr[i]); // dp[i-1]이 음수였다면 arr[i]로 업데이트됨
        sum_max = max(cum_sum[i], sum_max);
    }

    cout << sum_max;

    return 0;
}