#include <iostream>
using namespace std;

int n;
int matrix[2187][2187];
int cnt_neg1 = 0;
int cnt_0 = 0;
int cnt_pos1 = 0;

void recursion(int row, int col, int n)
{
    bool flag = false;
    int first = matrix[row][col];

    for (int i = row; i < row + n; i++)
    {
        for (int j = col; j < col + n; j++)
        {
            if (first != matrix[i][j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            break;
    }

    if (flag == false) // 종료 조건
    {
        switch (first)
        {
        case -1:
            cnt_neg1++;
            break;
        case 0:
            cnt_0++;
            break;
        case 1:
            cnt_pos1++;
            break;
        }
    }
    else
    {
        recursion(row, col, n / 3);
        recursion(row, col + n / 3, n / 3);
        recursion(row, col + 2 * n / 3, n / 3);
        recursion(row + n / 3, col, n / 3);
        recursion(row + n / 3, col + n / 3, n / 3);
        recursion(row + n / 3, col + 2 * n / 3, n / 3);
        recursion(row + 2 * n / 3, col, n / 3);
        recursion(row + 2 * n / 3, col + n / 3, n / 3);
        recursion(row + 2 * n / 3, col + 2 * n / 3, n / 3);
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
    cout << cnt_neg1 << '\n'
         << cnt_0 << '\n'
         << cnt_pos1;

    return 0;
}