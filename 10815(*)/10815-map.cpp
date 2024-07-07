#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    map<int, bool> m; // map은 key 중복 허용 X
    int tmp;

    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        m.insert(make_pair(tmp, true));
        // m.insert({tmp, true}); // C++11에서만 가능
    }

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        cout << m[tmp] << " ";
    }
}