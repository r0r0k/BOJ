#include <iostream>
#include <climits>
using namespace std;

int row, col, k;
bool board[2001][2001];     // 입력 받은 체스판
int prefix_sum[2001][2001]; // 이상적인 체스판을 채우기 위해 바꿔야 할 자리값의 누적합 (첫번째 자리는 함수내에서 B또는 W로 결정)

int find_min_prefix_sum(char color)
{
    bool first; // 처음에 어떤 색으로 시작할지 : B 는 0(false), W는 1(true)
    if (color == 'B')
        first = 0;
    else
        first = 1;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            prefix_sum[i][j] = board[i][j] ^ first;
            prefix_sum[i][j] += prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
            first = !first;
        }
        if (col % 2 == 0)
            first = !first;
    }

    int min_prefix_sum = INT_MAX;
    int res;
    for (int i = k; i <= row; i++)
    {
        for (int j = k; j <= col; j++)
        {
            res = prefix_sum[i][j] - prefix_sum[i - k][j] - prefix_sum[i][j - k] + prefix_sum[i - k][j - k];
            min_prefix_sum = min(min_prefix_sum, res);
        }
    }

    return min_prefix_sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col >> k;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            // bool로 파싱 (xor 연산의 효율과 메모리 절약을 위해)
            char tmp;
            cin >> tmp;
            tmp == 'B' ? board[i][j] = 0 : board[i][j] = 1;
        }
    }

    int res_min = min(find_min_prefix_sum('B'), find_min_prefix_sum('W'));
    cout << res_min;

    return 0;
}