#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, l; // 테스트 케이스 수, 체스판 한 변의 길이
bool visited[301][301];
int seq[301][301];
int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int r_target, c_target;

void bfs(int row, int col)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    seq[row][col] = 0;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == r_target && c == c_target)
            break;

        for (int i = 0; i < 8; i++)
        {
            int r_ = r + dr[i];
            int c_ = c + dc[i];

            if (r_ < 0 || r_ >= l || c_ < 0 || c_ >= l)
                continue;

            if (visited[r_][c_] == false)
            {
                visited[r_][c_] = true;
                seq[r_][c_] = seq[r][c] + 1;
                q.push({r_, c_});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    while (n--)
    {
        cin >> l;
        int r_start, c_start;

        cin >> r_start >> c_start;
        cin >> r_target >> c_target;
        bfs(r_start, c_start);
        cout << seq[r_target][c_target] << '\n';

        for (int i = 0; i < l; i++) // 다음 테스트 케이스를 위해 초기화
        {
            for (int j = 0; j < l; j++)
            {
                visited[i][j] = false;
                seq[i][j] = 0;
            }
        }
    }

    return 0;
}