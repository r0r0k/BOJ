#include <iostream>
using namespace std;

int n, limit;
int weight[101];
int value[101];
int dp[101][100001]; // 테이블 정의하기 : dp[i][j] 는 i번째 물건에서 현재 가방 무게의 limit이 j인 경우 가치합의 최댓값

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> limit;

    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
        cin >> value[i];
    }

    // 각 물건을 저장된 순서에 따라 i로 접근하여, limit이 j인 경우 가치합의 최댓값을 테이블을 누적해서 탐색
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= limit; j++)
        {
            if (weight[i] > j)           // 물건의 무게가 limit보다 큰 경우, 물건을 가방에 못 넣기 때문에 i - 1의 가치합을 그대로 가져옴
                dp[i][j] = dp[i - 1][j]; // 위쪽 선택

            else // 물건의 무게가 limit보다 작거나 같은 경우
                // 바로 위쪽과 : dp[i - 1][j]
                // 현재 물건의 가치를 더한 후 i - 1에서 현재 물건의 가치합을 뺀 상태에서의 가치합을 더한 결과를 비교 : value[i] + dp[i - 1][j - weight[i]]
                // max를 통해 가치합의 최댓값을 구해주지 않으면 매 테이블을 구하는 과정에서 i - 1만 탐색하여 구할 수 없음
                dp[i][j] = max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]]);
        }
    }

    cout << dp[n][limit]; // 마지막에는 최댓값이 존재하기 때문에 res_max로 매번 찾아주지 않아도 됨
    return 0;
}