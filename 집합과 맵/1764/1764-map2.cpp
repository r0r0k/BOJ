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

    map<string, int> m;
    set<string> s; // 교집합을 저장할 set : 사전순 정렬을 위해 vector대신 set을 사용
    int count = 0;

    string tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        m[tmp]++;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        m[tmp]++;
        if (m[tmp] == 2)
        {
            count++;
            s.insert(tmp);
        }
    }

    // 위에서 count와 insert를 안해줬으면 아래에서 이렇게 가능
    // for (auto it : m)
    // {
    //     if (it.second == 2)
    //     {
    //         count++;
    //         s.insert(it.first);
    //     }
    // }

    cout << count << '\n';
    for (auto it : s)
        cout << it << '\n';
}