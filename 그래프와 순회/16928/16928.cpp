#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n, m;
// 사다리와 뱀의 위치가 중복되지 않기 때문에 이진 탐색이 가능한 map으로 사용 가능
map<int, int> ladder;
map<int, int> snake;

int matrix[101]; // 1-index
queue<int> q;

void bfs(int start)
{
    q.push(start);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == 100) // 마지막 지점에 중간에 도착하면 최단거리를 구한 것이므로 종료해도됨
            return;

        for (int i = 1; i <= 6; i++) // 주사위 1~6까지 전부 테스트 : 이동하는 시간은 1초로 동일하기 때문에 bfs로 공평하게 가능
        {
            int v = u + i;
            if (v > 100) // 인덱스를 벗어나는 경우
                continue;

            if (ladder[v] != 0) // 해당 자리가 사다리라면, v를 사다리의 목적지로 이동
                v = ladder[v];
            if (snake[v] != 0) // 해당 자리가 뱀이라면, v를 뱀의 목적지로 이동
                v = snake[v];

            if (matrix[v] == 0) // 사다리나 뱀의 목적지여도 matrix[v] == 0이 아닌 경우, 이미 더 빨리 방문한 최단 거리가 존재한다는 뜻이므로 push하지 않아도 됨 : 최단거리 보장
            {
                q.push(v);
                matrix[v] = matrix[u] + 1;
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

    int u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        ladder[u] = v; // 사다리 출발지, 목적지
    }

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        snake[u] = v; // 뱀의 출발지, 목적지
    }

    bfs(1);
    cout << matrix[100];

    return 0;
}