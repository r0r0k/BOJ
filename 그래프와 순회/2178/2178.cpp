#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
bool matrix[101][101];    // 1-index
int seq[101][101];        // matrix의 해당 index에 몇번째로 방문했는지
int dr[] = {-1, 1, 0, 0}; // row : 상하좌우
int dc[] = {0, 0, -1, 1}; // col : 상하좌우
// int cnt = 0;

// bfs로 해야 최단 거리를 파악 가능(n, m이 한번 최단거리로 업데이트되면 matrix가 0이 되어 한번 더 호출되지 않기 때문)
void bfs(int row, int col)
{
    queue<pair<int, int>> q;
    q.push({row, col});

    matrix[row][col] = 0;
    seq[row][col] = 1;

    while (!q.empty())
    {
        // int cnt++;
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // if (r == n && c == m) // 이걸로 하면 반복문 순회를 조금 더 줄일 수 있음
        //     break;

        for (int i = 0; i < 4; i++)
        {
            int r_ = r + dr[i];
            int c_ = c + dc[i];

            if (r_ == 0 || c_ == 0 || r_ == n + 1 || c_ == m + 1) // segfault 검사
                continue;

            if (matrix[r_][c_] == 1)
            {
                q.push({r_, c_});
                matrix[r_][c_] = 0;
                seq[r_][c_] = seq[r][c] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    string line;
    for (int i = 1; i <= n; i++)
    {
        cin >> line;
        for (int j = 1; j <= m; j++)
            matrix[i][j] = line[j - 1] - '0';
    }

    bfs(1, 1);

    cout << seq[n][m];
    // cout << cnt;

    return 0;
}