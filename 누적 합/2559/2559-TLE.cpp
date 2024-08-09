#include <iostream>
#include <climits>
using namespace std;

int n;
int k;                   // 온도를 며칠동안 연속적으로 측정할지
int temperature[100001]; // 온도를 저장할 배열

// O(k(n-k+1))인데 n, k <= 100,000 이므로 k = n + (k / 2) 일때 최댓값을 가지고, n = 100000 , k = 50000 인 경우 TLE 발생
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> temperature[i];

    int res_max = INT_MIN;
    int res;
    for (int i = 1; i <= n - k + 1; i++)
    {
        res = 0;
        for (int j = i; j < i + k; j++)
        {
            res += temperature[j];
        }
        res_max = max(res_max, res);
    }

    cout << res_max;
    return 0;
}