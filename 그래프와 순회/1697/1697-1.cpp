#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int visited[100001]; // 방문 횟수를 count
int seq[100001];
int cnt = 0;

void bfs(int cur)
{
    queue<int> q;
    q.push(cur);
    visited[cur]++;
    seq[cur] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if (v == k && visited[k] == 3)
            break;

        if (v - 1 >= 0 && visited[v - 1] < 3)
        {
            visited[v - 1]++;
            if (visited[v - 1] == 1)
                seq[v - 1] = seq[v] + 1;
            else
                seq[v - 1] = min(seq[v - 1], seq[v] + 1);
            q.push(v - 1);
        }

        if (v + 1 <= 100000 && visited[v + 1] < 3)
        {
            visited[v + 1]++;
            if (visited[v + 1] == 1)
                seq[v + 1] = seq[v] + 1;
            else
                seq[v + 1] = min(seq[v + 1], seq[v] + 1);
            q.push(v + 1);
        }

        if (v * 2 <= 100000 && visited[v * 2] < 3)
        {
            visited[v * 2]++;
            if (visited[v * 2] == 1)
                seq[v * 2] = seq[v] + 1;
            else
                seq[v * 2] = min(seq[v * 2], seq[v] + 1);
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