#include <iostream>
using namespace std;

int n, m;
int arr[1000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int max_height = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        max_height = max(max_height, arr[i]);
    }

    int left = 0; // 높이가 1부터가 아닌 0부터이기 떄문
    int right = max_height;
    int mid = (left + right) / 2; // height를 나타냄 : right의 최댓값이 10억이기 때문에 int로 충분
    while (left <= right)
    {
        long res = 0; // arr[i] - mid의 합이 int를 넘어설 수 있음 (높이의 최댓값이 10억인데 여러번 더해지기 때문)
        for (int i = 0; i < n; i++)
        {
            if (arr[i] - mid > 0)
                res += arr[i] - mid;
        }

        if (res < m) // res가 총 필요한 나무 양보다 작은 경우, 높이를 낮춰서 나무를 더 잘라야 함
            right = mid - 1;
        else if (res >= m) // res가 총 필요한 나무 양보다 크거나 같은 경우, 높이를 더 키워서 나무를 더 적게 잘라서 최대 높이를 찾도록 설정
            left = mid + 1;

        mid = (left + right) / 2;
    }

    cout << mid;
    return 0;
}