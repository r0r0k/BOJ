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

    vector<int> vec(count);
    map<int, bool> m; // map은 key 중복 허용 X

    for (int i = 0; i < count; i++)
    {
        cin >> vec[i];
        m.insert(make_pair(vec[i], true));
        // m.insert({vec[i], true}); // C++11에서만 가능
    }

    cin >> count;
    int tmp;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        cout << m[tmp] << " ";
    }
}