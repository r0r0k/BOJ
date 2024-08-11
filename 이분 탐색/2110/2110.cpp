#include <iostream>
#include <algorithm>
using namespace std;

int n, c;        // 집의 개수, 공유기의 수
int arr[200000]; // 집의 좌표 : 좌표의 최댓값은 10억

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n); // 집간의 간격을 이진 탐색 하기 위해 오름차순으로 정렬

    int left = 1;                    // 집간의 최소 간격을 1으로 설ㅈ어
    int right = arr[n - 1] - arr[0]; // 집간의 최대 간격을 첫번째 집과 마지막번째 집으로 설정 (딱 2개만 있을 때 해당 간격이 최대가 됨)
    int mid = (left + right) / 2;    // 가장 인접한 두 공유기 사이의 최대 거리

    while (left <= right) // 모든 공유기의 간격이 최대로 공평하게 설치되야 이상적이므로 이분 탐색이 가능 (2개면 양끝, 3개면 양끝+정중앙)
    {
        int cnt = 1;       // 간격 내에 들어오는 집 : 첫번째 집은 설치되어 있다고 가정해야 하기 때문에 미리 1을 카운트해줌
        int prev = arr[0]; // 집의 간격을 업데이트 하기 위해 이전에 선택한 집을 첫번째 집으로 한 후 아래에서 업데이트

        for (int i = 1; i < n; i++)
        {
            if (arr[i] - prev >= mid) // 집의 간격이 설정한 간격(mid)보다 큰 경우
            {
                cnt++;         // 공유기 설치할 집 추가
                prev = arr[i]; // 해당 집을 기준으로 다시 간격 설정하기 위해 prev 설정
            }
        }

        if (cnt > c) // 간격의 최대 거리가 너무 짧게 설정된 경우
            left = mid + 1;

        else if (cnt < c) // 간격의 최대 거리가 너무 길게 설정된 경우
            right = mid - 1;

        else if (cnt == c) // 간격의 최대 길이를 늘려보며 더 가능한지 확인
            left = mid + 1;

        mid = (left + right) / 2;
    }

    cout << mid;
    return 0;
}