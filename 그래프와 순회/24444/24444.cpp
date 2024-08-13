#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, r; // 정점 수, 간선 수, 시작 정점
vector<int> adj[100001];
vector<bool> visited(100001);
vector<int> order(100001); // 방문 순서를 저장하는 벡터
int order_val = 1;
queue<int> q;

void bfs(int start)
{
    visited[start] = true;
    order[start] = order_val++;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (visited[v] == true)
                continue;

            visited[v] = true;
            order[v] = order_val++;

            q.push(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;

    int u, v;
    while (m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    bfs(r);

    for (int i = 1; i <= n; i++)
        cout << order[i] << '\n';

    return 0;
}