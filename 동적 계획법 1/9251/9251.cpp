#include <iostream>
using namespace std;

// 테이블 정의 : s1[i - 1], s2[j - 1] 까지의 문자열에서 LCS의 길이
// [i - 1]이나 [j - 1]을 참조할 때, [-1]을 참조하여 segfault가 나지 않기 위해 1-index 사용 (1-index를 쓰기 위해 문자열 s1, s2 index 접근에는 -1을 해줘야함)

int dp[1001][1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])          // 두 문자가 같은 경우
                dp[i][j] = dp[i - 1][j - 1] + 1; // 왼쪽 대각선에서 +1 을 해줌
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 왼쪽과 위쪽에서 더 큰 값을 골라줌
        }
    }

    cout << dp[s1.length()][s2.length()];
    return 0;
}