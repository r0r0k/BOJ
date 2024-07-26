#include <iostream>
using namespace std;

int n, m;
int arr[100001];
int cum_sum[100001]; // 테이블 정의하기 : cum_sum[i] 는 i까지의 누적핪
int start_, end_;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    cum_sum[1] = arr[1]; // 초기값 지정
    for (int i = 2; i <= n; i++)
        cum_sum[i] += cum_sum[i - 1] + arr[i]; // 점화식

    for (int i = 0; i < m; i++)
    {
        cin >> start_ >> end_;
        cout << cum_sum[end_] - cum_sum[start_ - 1] << '\n';
    }

    return 0;
}