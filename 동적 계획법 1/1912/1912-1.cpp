#include <iostream>
using namespace std;

int n;
int arr[100001];       // 입력값을 저장하는 배열
int cum_sum[100001];   // 현재까지의 누적합을 저장하는 배열 (누적합이 음수가 되는 경우 다음 누적합은 새로운 arr 부터 시작)
int sum_max;           // 현재 연속합의 최댓값
bool neg_flag = false; // 누적합이 음수가 되는 경우를 판단하는 변수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    // 초기값 정하기 : 사실 생각해보면 1-index에서는 (i - 1)이 점화식 항에 포함된 경우 딱히 안해줘도 되긴함
    cum_sum[1] = arr[1];
    sum_max = arr[1];

    // 초기값을 정해주고 neg_flag를 확인 안해주면, [-1 1] 이 들어온 경우 1이 아닌 0이 최댓값이 되버림
    if (cum_sum[1] < 0)
        neg_flag = true;

    for (int i = 2; i <= n; i++)
    {
        if (neg_flag == true)
        {
            cum_sum[i] = arr[i];
            sum_max = max(sum_max, cum_sum[i]); // 연속합의 최댓값을 비교

            if (cum_sum[i] >= 0)
                neg_flag = false;
        }

        else
        {
            cum_sum[i] = cum_sum[i - 1] + arr[i]; // 누적합 계산

            if (cum_sum[i] < 0) // 누적합이 음수가 되는 순간 neg_flag를 true로 바꿔서 다음 반복문에서 새로운 누적합 계산
                neg_flag = true;
            else
                sum_max = max(sum_max, cum_sum[i]); // 연속합의 최댓값을 비교
        }
    }

    cout << sum_max;

    return 0;
}