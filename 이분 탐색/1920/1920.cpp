#include <iostream>
#include <unordered_set>
using namespace std;

int n;
unordered_set<int> s; // 탐색이 필요없기 때문에 해시 테이블로 find 하는게 훨씬 빠름

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int tmp;
    while (n--)
    {
        cin >> tmp;
        s.insert(tmp);
    }

    cin >> n;
    while (n--)
    {
        cin >> tmp;
        if (s.find(tmp) != s.end())
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}