#include <iostream>
using namespace std;

int n, m;
int arr[1025][1025];
int dp[1025][1025]; // 테이블 정하기 : dp[i][j] 는 (1, 1) 부터 (i, j) 까지의 직사각형의 합

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    // 초기값은 row, col이 0인 경우 어쩌피 0으로 초기화되어있어서 해줄 필요 없음
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            // 점화식 찾기 : dp[i - 1][j] + dp[i][j - 1] 에서 중복되는 dp[i - 1][j - 1]을 빼주고 arr[i][j]를 더해주면 됨
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];

    int x1, y1, x2, y2; // 헤더 파일에 y1 이라는 변수나 함수 이름이 있어서 전역 변수에는 선언 불가능 (count, max처럼)
    while (m--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}