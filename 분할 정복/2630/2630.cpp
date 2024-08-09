#include <iostream>
using namespace std;

int n;
int matrix[128][128];
int white_cnt = 0;
int blue_cnt = 0;

void recursion(int row, int col, int n)
{
    int res = 0;
    for (int i = row; i < row + n; i++)
        for (int j = col; j < col + n; j++)
            res += matrix[i][j];

    if (res == n * n)
        blue_cnt++;
    else if (res == 0)
        white_cnt++;
    else
    {
        recursion(row, col, n / 2);
        recursion(row, col + n / 2, n / 2);
        recursion(row + n / 2, col, n / 2);
        recursion(row + n / 2, col + n / 2, n / 2);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    recursion(0, 0, n);

    cout << white_cnt << '\n'
         << blue_cnt;
    return 0;
}