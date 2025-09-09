#include <iostream>
#include <queue>
using namespace std;

int n, m;
int matrix[1001][1001][2]; // 1-index
// [row][col][0] 은 현재까지 이동한 최단거리를 나타내고, [row][col][1]은 현재까지 이동했을 때 벽을 뚫고온 적이 있는 경우의 최단 거리
queue<pair<int, int>> q;

int dr[] = {-1, 1, 0, 0}; // 상하좌우
int dc[] = {0, 0, -1, 1}; // 상하좌우

// 이렇게 matrix 안에 하면 matrix[i][j][0]이 업데이트 되어 벽을 뚫고 다시 방문하는 경우 분리가 안됨
void bfs(int row, int col)
{
    q.push({row, col});
    matrix[row][col][0] = 1; // 시작점을 1로 설정해줌

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        cout << "r " << r << " c" << c << '\n';
        if (r == n && c == m) // 0-index
            return;

        for (int i = 0; i < 4; i++)
        {
            int _r = r + dr[i];
            int _c = c + dc[i];

            if (_r <= 0 || _c <= 0 || _r > n || _c > m)
                continue;

            if (matrix[_r][_c][0] == 0) // 벽이 아닌 경우
            {
                if (matrix[r][c][1] == 0) // 이전에 아직 벽을 뚫은 적이 없는 경우
                {
                    matrix[_r][_c][0] = matrix[r][c][0] + 1;
                    q.push({_r, _c});
                }
                else // 이전에 벽을 뚫어서 온 경우
                {
                    matrix[_r][_c][1] = matrix[r][c][1] + 1;
                    q.push({_r, _c});
                }
            }

            else if (matrix[_r][_c][0] == 1) // 벽인 경우
            {
                if (matrix[r][c][1] == 0) // 이전에 아직 벽을 뚫은 적이 없는 경우
                {
                    matrix[_r][_c][1] = matrix[r][c][0] + 1;
                    q.push({_r, _c});
                }
                else // 이전에 벽을 뚫은 경우는 더이상 진행 불가
                    continue;
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

    for (int i = 1; i <= n; i++)
    {
        string line;
        cin >> line;
        for (int j = 1; j <= m; j++)
            matrix[i][j][0] = line[j - 1] - '0';
    }

    bfs(1, 1);

    if (matrix[n][m][0] == 0 && matrix[n][m][1] == 0) // 도달 불가능
        cout << "-1";

    else if (matrix[n][m][0] == 0) // 뚫지 않고 도달 불가능
        cout << matrix[n][m][1];

    else // 뚫지 않고 도달 가능
        cout << matrix[n][m][0];

    return 0;
}
