#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    set<int> s;
    int tmp;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        s.insert(tmp);
    }

    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        // set은 이진 트리로 구현되어 있어서 find시 자동으로 이진 탐색 가능 O(logn)
        // vector는 O(n)
        cout << (s.end() != s.find(tmp)) << " "; // find 실패시 s.end()가 반환되기 때문에 s.end()가 아니면 1 반환
    }
}