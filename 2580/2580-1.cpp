#include <iostream>
#include <vector>
using namespace std;

int board[9][9];              // 스도쿠 판의 상태를 저장할 배열
vector<pair<int, int>> blank; // 처음 입력시 스도쿠의 빈칸을 저장할 벡터
int blank_count = 0;          // 초기 빈칸의 개수 : 빈칸이 전부 채워졌을 때 종료하기 위한 변수
bool is_end = false;          // 모든 판이 입력되었는지 판단하는 변수

bool check(pair<int, int> blank, int val)
{
    int row = blank.first;
    int col = blank.second;

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
    if (cur == blank_count)
    {
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
        is_end = true;
        return;
    }

    for (int i = 1; i <= 9; i++) // 1부터 9까지 해당 자리에 들어가는지 check를 호출
    {

        auto pair = blank[cur];
        if (check(pair, i))
        {
            board[pair.first][pair.second] = i;
            sudoku(cur + 1);

            // 아래에서 sudoku(cur + 1);을 호출한 후 해당 자리를 0으로 바꾸어 주는데, 이렇게 되면
            // 이미 출력이 끝났는데 다시 반복문에 들어와서, 연쇄적으로 처음부터 sudoku(cur + 1); 을 다시 호출하여 무한 출력이 됨
            if (is_end)
                break;
            board[pair.first][pair.second] = 0; // 다시 돌아왔으면 이전에 값들은 0으로 다시 초기화해줘야함
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                blank.push_back({i, j});
                blank_count++;
            }
        }
    }

    sudoku(0);
    return 0;
}