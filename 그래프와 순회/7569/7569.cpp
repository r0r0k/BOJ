#include <iostream>
#include <queue>
using namespace std;

struct coor
{
    int row;
    int col;
    int height;
};

int N, M, H;
int matrix[100][100][100]; // row, col, height : 0-index
queue<coor> q;

int dr[] = {-1, 1, 0, 0, 0, 0}; // 앞 뒤 좌 우 상 하
int dc[] = {0, 0, -1, 1, 0, 0}; // 앞 뒤 좌 우 상 하
int dh[] = {0, 0, 0, 0, 1, -1}; // 앞 뒤 좌 우 상 하

void bfs()
{
    while (!q.empty())
    {
        int row = q.front().row;
        int col = q.front().col;
        int height = q.front().height;

        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int r = row + dr[i];
            int c = col + dc[i];
            int h = height + dh[i];

            if (r < 0 || c < 0 || h < 0 || r >= N || c >= M || h >= H)
                continue;

            if (matrix[r][c][h] == 0)
            {
                coor cor;
                cor.row = r;
                cor.col = c;
                cor.height = h;

                q.push(cor);
                matrix[r][c][h] = matrix[row][col][height] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H;

    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> matrix[i][j][k];
                if (matrix[i][j][k] == 1)
                {
                    coor cor;
                    cor.row = i;
                    cor.col = j;
                    cor.height = k;
                    q.push(cor); // 복사해서 넣기 때문에 상관X
                }
            }
        }
    }

    bfs();

    int day = 0;
    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (matrix[i][j][k] == 0) // 익지 않은 토마토가 존재하면 -1 출력 후 종료
                {
                    cout << "-1";
                    return 0;
                }
                day = max(day, matrix[i][j][k]);
            }
        }
    }

    cout << day - 1;
    return 0;
}