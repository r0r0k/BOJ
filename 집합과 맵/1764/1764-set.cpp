#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;

    cin >> N >> M;

    set<string> s1; // 처음 입력 받을 string
    set<string> s2; // 교집합을 저장할 set : 사전순 정렬을 위해 vector대신 set을 사용
    int count = 0;

    string tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        s1.insert(tmp);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        if (s1.find(tmp) != s1.end())
        {
            count++;
            s2.insert(tmp);
        }
    }

    cout << count << '\n';
    for (auto it : s2)
        cout << it << '\n';
}