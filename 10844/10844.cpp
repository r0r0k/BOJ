#include <iostream>
using namespace std;

int n;
int dp[101][10]; // dp[i][j] : i번째 자리에서 j 값을 가질 때 가능한 계단 수의 개수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    // 초기값 설정
    // 1. 길이가 1일 때는, 1 ~ 9 까지 1개씩만 존재 (0으로 시작할 수 없기 때문)
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    // 2. 길이가 2일 때 0, 1, 9 는 앞에 1개만 올 수 있기 때문에 1개씩만 존재하고(10, 21, 89), 나머지는 앞에 2개가 올 수 있기 때문에 2개씩 존재
    // for (int i = 0; i <= 9; i++)
    // {
    //     dp[2][i] = 2;
    //     if (i == 0 || i == 1 || i == 9)
    //         dp[2][i]--;
    // }

    // 점화식 찾기 : 0도 가능하다는 것을 기억해야함
    // j = 0인 경우에는 j - 1이 존재할 수 없기 때문에 j + 1만 더해주고, 이외에는 j - 1과 j + 1을 다 더해주면 됨
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % 1000000000;
            else if (j == 9)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % 1000000000;
            else
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }

    // 길이가 n인 자리에 들어갈 수 있는 정수에 대한 계단수의 개수를 전부 더해주면 결과 값이 나옴
    int res = 0;
    for (int i = 0; i <= 9; i++)
        res = (res + dp[n][i]) % 1000000000;

    cout << res;

    return 0;
}