#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;

    cin >> N >> M;

    map<string, bool> m;
    set<string> s; // 교집합을 저장할 set : 사전순 정렬을 위해 vector대신 set을 사용
    int count = 0;

    string tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        m[tmp] = true;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        auto it = m.insert(make_pair(tmp, true));
        if (it.second == false)
        {
            count++;
            s.insert(tmp);
        }
    }

    cout << count << '\n';
    for (auto it : s)
        cout << it << '\n';
}