#include <iostream>
#include <map>
using namespace std;

int n;
map<int, int> line; // 왼쪽 전봇대 번호를 key, 오른쪽 전봇대 번호를 value로 가지는 전깃줄의 정보를 저장하는 map (두 값을 연결하고, 바로 정렬하기 위해 map 사용)
int arr[101];       // 정렬된 왼쪽 전봇대에 연결된 오른쪽 전봇대의 번호
int dp[101];        // 정렬된 왼쪽 전봇대에 연결된 오른쪽 전봇대의 i번째 수를 끝으로 하는 부분 수열의 길이
int res_max;        // 가장 긴 부분 수열의 길이

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int left, right;
    for (int i = 1; i <= n; i++)
    {
        cin >> left >> right;
        line[left] = right;
        dp[i] = 1; // 초기값 설정
    }

    int i = 1;
    for (auto it : line)
    {
        arr[i] = it.second; // 정렬된 왼쪽 전봇대 번호에 의해 순서가 정해진 오른쪽 전봇대 번호를 arr에 대입
        i++;
    }

    // 증가하는 부분 수열의 길이 찾기
    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (arr[i] > arr[j])
                dp[i] = max(dp[j] + 1, dp[i]);
        }

        res_max = max(res_max, dp[i]);
    }

    // 제거할 전깃줄을 출력해야 하기 때문에, 전체 전깃줄 개수에서 증가하는 부분 수열의 개수를 빼주면 제거할 전깃줄 개수가 나옴
    cout << n - res_max;

    return 0;
}