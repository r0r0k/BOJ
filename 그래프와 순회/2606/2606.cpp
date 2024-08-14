#include <iostream>
#include <vector>
using namespace std;

int n, m;
int cnt = 0;
vector<int> adj[101];
vector<bool> visited(101);

void dfs(int cur)
{
    cnt++;
    visited[cur] = true;
    for (auto v : adj[cur])
    {
        if (visited[v] == true)
            continue;
        dfs(v);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << cnt - 1; // 첫번째 컴퓨터는 빼줘야 하기 때문
    return 0;
}