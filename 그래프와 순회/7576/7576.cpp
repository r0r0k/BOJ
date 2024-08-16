#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int matrix[1000][1000];
queue<pair<int, int>> q;
int dr[] = {-1, 1, 0, 0}; // 상하좌우
int dc[] = {0, 0, -1, 1}; // 상하좌우

void bfs()
{
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = row + dr[i];
            int c = col + dc[i];

            if (r < 0 || c < 0 || r >= n || c >= m)
                continue;

            if (matrix[r][c] == 0) // -1 일때는 토마토가 없는 자리이고, 1 이상일 때는 이미 익은 토마토이므로 건들면 안됨
            {
                q.push({r, c});
                matrix[r][c] = matrix[row][col] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1)
                q.push({i, j});
        }

    bfs();

    int day_max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0) // bfs 이후 익지 않은 토마토가 존재한다면 -1을 출력 후 종료
            {
                cout << "-1";
                return 0;
            }
            day_max = max(day_max, matrix[i][j]);
        }
    }

    cout << day_max - 1; // 최대로 지난 날에서 -1을 해준 후 출력해주면 됨 (matrix는 처음부터 익은 토마토가 1이므로, 해당 토마토를 0일으로 해야 되기 때문)

    return 0;
}