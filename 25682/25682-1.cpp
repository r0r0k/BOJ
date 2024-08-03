#include <iostream>
#include <climits>
using namespace std;

int row, col, k;
bool board[2001][2001];           // 입력 받은 체스판
int white_prefix_sum[2001][2001]; // 첫번째가 B로 시작하는 이상적인 체스판으로 만들기 위해 바꿔야 하는 자리의 누적합
int black_prefix_sum[2001][2001]; // 첫번째가 W로 시작하는 이상적인 체스판으로 만들기 위해 바꿔야 하는 자리의 누적합
// 첫번째가 B인지 W인지로 나눠서 구하면 모든 경우의 누적합을 구할 수 있음

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col >> k;

    bool black = 0;
    bool white = 1;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            // bool로 파싱 (xor 연산의 효율과 메모리 절약을 위해)
            char tmp;
            cin >> tmp;
            tmp == 'B' ? board[i][j] = 0 : board[i][j] = 1;

            // 누적합을 계산하기 위해 이상적인 체스판의 자리와 다른 경우 1을 대입해야함

            // 1. XOR으로 같으면 0, 다르면 1 저장
            white_prefix_sum[i][j] = white ^ board[i][j];
            // 2. 2차원 배열 누적합 계산
            white_prefix_sum[i][j] += white_prefix_sum[i - 1][j] + white_prefix_sum[i][j - 1] - white_prefix_sum[i - 1][j - 1];

            // 1. XOR으로 같으면 0, 다르면 1 저장
            black_prefix_sum[i][j] = black ^ board[i][j];
            // 2. 2차원 배열 누적합 계산
            black_prefix_sum[i][j] += black_prefix_sum[i - 1][j] + black_prefix_sum[i][j - 1] - black_prefix_sum[i - 1][j - 1];

            // 색이 번갈아가서 나와야 하므로 not 연산 대입
            black = !black;
            white = !white;
        }
        if (col % 2 == 0) // col이 짝수라면, BWBW 이후에 다음 줄로 갈 때, W로 다시 바꿔줘야함 (홀수라면 안바꿔줘도 됨)
        {
            black = !black;
            white = !white;
        }
    }

    // 두 prefix_sum 중 (k x k) 체스판의 바꿔야 하는 누적합의 최솟값을 구해서 비교하면 된다.
    int res_min = INT_MAX;
    int w_prefix_sum, b_prefix_sum;
    for (int i = k; i <= row; i++)
    {
        for (int j = k; j <= col; j++)
        {
            w_prefix_sum = white_prefix_sum[i][j] - white_prefix_sum[i][j - k] - white_prefix_sum[i - k][j] + white_prefix_sum[i - k][j - k];
            b_prefix_sum = black_prefix_sum[i][j] - black_prefix_sum[i][j - k] - black_prefix_sum[i - k][j] + black_prefix_sum[i - k][j - k];
            res_min = min(res_min, min(w_prefix_sum, b_prefix_sum));
        }
    }

    cout << res_min;
    return 0;
}