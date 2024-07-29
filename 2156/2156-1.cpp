#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10001];   // 포도주의 양을 저장하는 배열
int dp[10001][3]; // 테이블 정의하기 : dp[i][j] 는 i번째 포도주를, 이전 포도주로부터 j번째로 연속해서 마셨을 때의 최댓값
int res_max;      // 꼭 마지막 포도주를 마실 필요가 없기 때문에 max를 선언 (포도주의 양은 음이 아닌 정수)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    // 초기값 설정 : [1][0]과 [1][2]는 이미 선언과 동시에 0으로 초기화
    dp[1][1] = arr[1];
    // res_max = dp[1][1];

    for (int i = 2; i <= n; i++)
    {
        // 점화식 찾기
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}); // i번째 포도주를 먹지 않고 그대로 올라온 것 (꼭 2칸만 뛰어 넘을 필요가 없기 때문)
        // dp[i][1] = max({dp[i - 1][0], dp[i - 2][1], dp[i - 2][2]}) + arr[i];
        dp[i][1] = dp[i - 1][0] + arr[i]; // 1번 연속으로 마셨을 때는 2단계 뛰어넘어서 마셔야 하기 때문
        dp[i][2] = dp[i - 1][1] + arr[i]; // 2번 연속으로 마셨을 때는 1단계 이전의 포도주에서 연속으로 마셔야 하기 때문

        // res_max = max({res_max, dp[i][0], dp[i][1], dp[i][2]}); // 마지막 포도주를 마실 필요가 없기 때문에 max를 따로 찾아줘야함
    }

    // cout << res_max;
    cout << max({dp[n][0], dp[n][1], dp[n][2]});

    return 0;
}