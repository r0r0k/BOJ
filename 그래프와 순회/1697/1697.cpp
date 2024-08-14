#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
bool visited[100001]; // 방문 횟수를 count
int seq[100001];

void bfs(int cur)
{
    queue<int> q;
    q.push(cur);
    visited[cur] = true;
    seq[cur] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if (v == k)
            break;

        if (v - 1 >= 0 && visited[v - 1] == false)
        {
            visited[v - 1] = true;
            seq[v - 1] = seq[v] + 1;
            q.push(v - 1);
        }

        if (v + 1 <= 100000 && visited[v + 1] == false)
        {
            visited[v + 1] = true;
            seq[v + 1] = seq[v] + 1;
            q.push(v + 1);
        }

        if (v * 2 <= 100000 && visited[v * 2] == false)
        {
            visited[v * 2] = true;
            seq[v * 2] = seq[v] + 1;
            q.push(v * 2);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    bfs(n);

    cout << seq[k];

    return 0;
}