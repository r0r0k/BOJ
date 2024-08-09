#include <iostream>
#include <algorithm>
using namespace std;

int k, n;
int arr[10000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n;

    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + k);

    int tmp = sum / n;        // 1. 합을 기존 k개로 나눈다.
    int q = arr[k - 1] / tmp; // 2. 나눈 몫을 최댓값으로 나눈다.

    int res = 0;
    while (1)
    {
        for (int i = 0; i < k; i++)
            res += arr[i] / tmp; // 3. 모든 요소에 합을 k개로 나눈 값을 나누어 몫을 구한다.
        if (res == n)            // 몫이 구하려고 하는 n개와 같으면 종료
            break;
        res = 0;              // 아니면 초기화
        q++;                  // 4. tmp를 재설정하여 최댓값을 한 조각 더 크게 나누기 위해 q++을 해준다.
        tmp = arr[k - 1] / q; // 5. q++한 값을 최댓값에 나누어 다시 tmp를 구한다.
    }

    cout << tmp;

    return 0;
}