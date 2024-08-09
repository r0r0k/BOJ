#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int set_size, string_count;
    cin >> set_size >> string_count;

    map<string, bool> m;
    string tmp;

    for (int i = 0; i < set_size; i++)
    {
        cin >> tmp;
        m.insert(make_pair(tmp, true));
        // m.insert({tmp, true});
    }

    int count = 0;
    for (int i = 0; i < string_count; i++)
    {
        cin >> tmp;
        if (m.end() != m.find(tmp)) // 7836 KB, 64 ms
            count++;
        // if (m[tmp]) // key가 없으면 0 반환 : 9816 KB, 84 ms
        //     count++;
    }

    cout << count;
}