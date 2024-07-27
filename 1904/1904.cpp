#include <iostream>
using namespace std;

int n;
int dp[1000001]; // 테이블 정의 : dp[i] 는 길이가 i인 2진 수열의 개수를 15746으로 나눈 나머지

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    // 초기값 찾기 : i - 2 까지 점화식의 항이 존재하기 때문에 i = 2까지 구해줘야함
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746; // 점화식 찾기

    cout << dp[n];

    return 0;
}