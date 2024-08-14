#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, r;
vector<int> adj[1001];
bool visited[1001];

void dfs(int cur)
{
    cout << cur << " ";
    visited[cur] = true;

    for (auto v : adj[cur])
    {
        if (visited[v])
            continue;
        dfs(v);
    }
}

void bfs(int cur)
{
    queue<int> q;
    q.push(cur);
    cout << cur << " ";
    visited[cur] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (visited[v])
                continue;

            visited[v] = true;
            cout << v << " ";
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

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(r);
    cout << '\n';

    for (int i = 1; i <= n; i++)
        visited[i] = false;

    bfs(r);
    cout << '\n';

    return 0;
}