#include <iostream>
#include <vector>
using namespace std;

int n, m;
int matrix[50][50];       // 입력이 0-index 이므로, 어쩌피 검사를 해줘야하기 때문에 사이즈에 딱 맞게 선언
int dr[] = {-1, 1, 0, 0}; // row 방향 : 상, 하, 좌, 우
int dc[] = {0, 0, -1, 1}; // col 방향 : 상, 하, 좌, 우
int cnt = 0;

void dfs(int row, int col)
{
    matrix[row][col] = 0;

    for (int i = 0; i < 4; i++) // 상, 하, 좌, 우 순서로 판단
    {
        int r = row + dr[i];
        int c = col + dc[i];

        if (r < 0 || r >= n || c < 0 || c >= m) // index가 범위를 넘어서는 경우
            continue;

        if (matrix[r][c] == 1)
            dfs(r, c);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n1, n2;
    cin >> n1; // 반복 횟수

    while (n1--)
    {
        cin >> n >> m >> n2;
        int row, col;
        while (n2--) // 정점 입력 횟수
        {
            cin >> row >> col;
            matrix[row][col] = 1;
        }

        for (int i = 0; i < n; i++) // row
        {
            for (int j = 0; j < m; j++) // col
            {
                if (matrix[i][j] == 1)
                {
                    dfs(i, j);
                    cnt++; // 구역 1개마다 cnt를 증가시켜줌
                }
            }
        }

        cout << cnt << '\n';
        cnt = 0;
        // matrix의 경우 한번 dfs를 수행하면 matrix가 전부 0으로 바뀌므로 따로 초기화 해줄 필요는 없음
    }

    return 0;
}