#include <iostream>
#include <vector>
using namespace std;

int board[9][9];     // 스도쿠 판의 상태를 저장할 배열
bool is_end = false; // 모든 판이 입력되었는지 판단하는 변수

bool check(int row, int col, int val)
{
    for (int i = 0; i < 9; i++) // blank가 위치하는 board의 가로, 세로에 해당 val 값이 이미 존재하는지 확인
    {
        if (board[row][i] == val || board[i][col] == val)
            return false;
    }

    row = (row / 3) * 3;
    col = (col / 3) * 3;

    for (int i = row; i < row + 3; i++) // blank가 위치하는 board 3X3 영역에 val 값이 이미 존재하는지 확인
    {
        for (int j = col; j < col + 3; j++)
        {
            if (board[i][j] == val)
                return false;
        }
    }

    return true;
}

void sudoku(int cur)
{
    if (cur == 81)
    {
        is_end = true;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j];
                if (j < 8)
                    cout << " ";
            }
            if (i < 8)
                cout << "\n";
        }
        return;
    }

    int row = cur / 9;
    int col = cur % 9;

    if (board[row][col])
    {
        sudoku(cur + 1);
        return;
    }

    for (int i = 1; i <= 9; i++) // 1부터 9까지 해당 자리에 들어가는지 check를 호출
    {
        if (check(row, col, i))
        {
            board[row][col] = i;
            sudoku(cur + 1);

            if (is_end)
                break;
            board[row][col] = 0; // 다시 돌아왔으면 이전에 값들은 0으로 다시 초기화해줘야함
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    sudoku(0);
    return 0;
}
