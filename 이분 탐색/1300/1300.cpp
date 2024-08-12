#include <iostream>
using namespace std;

long n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    long left = 1;      // B[k]가 될 수 있는 최솟값
    long right = n * n; // B[k]가 될 수 있는 최댓값
    long mid;           // B[k] 후보

    int res; // B[k] 의 최종값 저장
    while (left <= right)
    {
        long cnt = 0; // B[K] 보다 작은 값의 개수
        mid = (left + right) / 2;

        // mid = (left + right) / 2;
        for (int i = 1; i <= n; i++)
            // row에 대해 1 ~ n 까지 검사
            // (mid / i)는 i번째 row에서 mid보다 작은 col값의 개수임
            // 왜냐하면 i번째 row는 col이 증가할 수록, 이전 col에서 i씩 증가하는데 (mid / i)를 하면 딱 mid보다 작은 i번째 row에서의 col 개수가 나옴
            // 그런데, col 개수는 n개이므로, (mid / i) 가 n보다 커질 수 있기 때문에, 해당 경우에 min()을 통해 검사해서 n을 넣어줘야함
            cnt += min(mid / i, n);

        if (cnt > k)
        {
            // B[k] = mid 일 때, mid보다 작은 값의 개수가 k보다 많은 경우, mid를 줄여서 후보를 줄여야함
            right = mid - 1;
            // mid의 값이 중복되는 경우 cnt를 넘을 수 있기 때문에 여기서도 res를 업데이트해줘야함
            res = mid;
        }

        else if (cnt < k) // B[k] = mid 일 때, mid보다 작은 값의 개수가 k보다 적은 경우, mid를 늘여서 후보를 늘여야함
            left = mid + 1;

        else if (cnt == k)
        {
            // B[k] = mid 일 때, mid보다 작은 값의 개수가 k와 같은 경우,
            // B[k] = mid가 더 작아질 때도 k를 만족하는 경우가 생기면 그때가 정답이므로 mid를 줄여서 다시 검사해봐야함 (mid가 꼭 B[k]라는 보장이 없기 때문)
            // 예를 들어 mid가 5인데, 실제 B[k] = 4 인 경우, mid를 줄여서 4일 때로 판단해야함
            right = mid - 1;
            res = mid;
        }
    }

    cout << res;
    return 0;
}