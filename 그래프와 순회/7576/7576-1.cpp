#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
bool visited[1000][1000];
int seq[1000][1000];
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

            if (visited[r][c] == 0)
            {
                q.push({r, c});
                visited[r][c] = 1;
                seq[r][c] = seq[row][col] + 1;
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

    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tmp;
            if (tmp == 1)
            {
                visited[i][j] = 1;
                q.push({i, j});
            }
            if (tmp == -1)
                visited[i][j] = 1;
        }
    }

    bfs();

    int day_max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0) // bfs 이후 방문하지 않은 토마토가 존재한다면 -1을 출력 후 종료
            {
                cout << "-1";
                return 0;
            }
            day_max = max(day_max, seq[i][j]);
        }
    }

    cout << day_max;

    return 0;
}