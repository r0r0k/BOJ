#include <iostream>
using namespace std;

int n;
long ex;
int matrix[5][5]; // 기존 행렬

int recursion(int row, int col, long exponent)
{
    if (exponent == 1)
        return matrix[row][col];

    int res = 0;
    if (exponent % 2 == 0)
    {
        for (int i = 0; i < n; i++)
            res += (recursion(i, col, exponent / 2) * recursion(row, i, exponent / 2)) % 1000;
        return res % 1000;
    }
    else
    {
        for (int i = 0; i < n; i++)
            res += (recursion(i, col, exponent / 2 + 1) * recursion(row, i, exponent / 2)) % 1000;
        return res % 1000;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ex;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << recursion(i, j, ex) % 1000 << " ";
        cout << '\n';
    }

    return 0;
}