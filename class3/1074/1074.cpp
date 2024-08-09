#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int cnt = 0;

// N <= 15이므로 한 변의 길이가 최대 2^15여서 재귀를 통해 모든 칸을 순회하는 O(N^2)은 시간초과가 발생해서 아래의 방식으로 풀어야함
void recursion(int row, int col, int n)
{
    if (n == 2) // 마지막 종료 조건은 무조건 n == 2 일때, (r, c)에 위치하게 됨
    {
        cnt += n * (r - row) + (c - col);
        return;

        // for (int i = row; i < row + n; i++)
        //     for (int j = col; j < col + n; j++)
        //     {
        //         if (i == r && j == c)
        //             return;
        //         cnt++;
        //     }
    }

    int half = n / 2;
    if (r < row + half && c < col + half) // 제 1사분면
    {
        recursion(row, col, half);
    }

    else if (r < row + half && c >= col + half) // 제 2사분면
    {
        cnt += half * half;
        recursion(row, col + half, half);
    }

    else if (r >= row + half && c < col + half) // 제 3사분면
    {
        cnt += 2 * half * half;
        recursion(row + half, col, half);
    }

    else if (r >= row + half && c >= col + half) // 제 4사분면
    {
        cnt += 3 * half * half;
        recursion(row + half, col + half, half);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r >> c;
    recursion(0, 0, pow(2, n));

    cout << cnt;

    return 0;
}