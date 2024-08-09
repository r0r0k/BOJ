#include <iostream>
using namespace std;

int n;
int k;                   // 온도를 며칠동안 연속적으로 측정할지
int temperature[100001]; // 온도를 저장할 배열
int cum_sum[100001];     // 누적합을 저장할 배열

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    // 온도 입력 받기
    for (int i = 1; i <= n; i++)
        cin >> temperature[i];

    // 초기값 지정 : 첫번째 누적합 계산
    for (int i = 1; i <= k; i++)
        cum_sum[k] += temperature[i];

    // 누적합을 계산해가며 최댓값 찾기
    int res_max = cum_sum[k];
    for (int i = k + 1; i <= n; i++)
    {
        cum_sum[i] = temperature[i] + (cum_sum[i - 1] - temperature[i - k]);
        res_max = max(res_max, cum_sum[i]);
    }

    cout << res_max;
    return 0;
}