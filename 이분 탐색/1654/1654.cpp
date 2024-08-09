#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int k, n;
int arr[10000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n;

    int max_length = 0; // 입력 받은 길이의 최댓값을 저장
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
        max_length = max(max_length, arr[i]);
    }

    // 1 ~ max_length 까지 이진 탐색
    // right의 최댓값이 2^31 - 1 이므로, right가 최댓값일 경우 int overflow가 발생해서 long으로 선언
    long left = 1;
    long right = max_length;
    long mid = (left + right) / 2;

    int found_max = 0;
    while (left <= right)
    {
        // mid로 나누었을 때 랜선의 개수를 저장하기 위한 변수
        // arr[i]가 전부 2^31 - 1이고, mid가 작은 경우 overflow가 날 수도 있기 때문에 long으로 선언
        long res = 0;
        for (int i = 0; i < k; i++)
            res += arr[i] / mid;

        if (res < n) // 랜선의 개수가 n 보다 작은 경우, mid를 줄여야 하기 때문에 mid 기준 왼쪽으로 이동
            right = mid - 1;

        // 랜선의 개수가 n 보다 크거나 같은 경우, mid를 더 키워보며 max값을 찾음
        // 문제에서 랜선의 개수가 정확히 n개가 아니라, n개를 넘어서도 되기 때문에 >= 로 계산해야함
        else if (res >= n)
        {
            if (found_max < mid)
                found_max = mid;
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }

    cout << found_max;
    return 0;
}