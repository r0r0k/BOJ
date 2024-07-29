#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10001]; // 포도주의 양을 저장하는 배열
int dp[10001];  // 테이블 정의하기 : dp[i]는 i번째 포도주를 마셨을 때의 최댓값

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    // 초기값 설정
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for (int i = 3; i <= n; i++)
        // 점화식 찾기
        dp[i] = max({dp[i - 1], dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]});

    cout << dp[n];

    return 0;
}