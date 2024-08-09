#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int set_size, string_count;
    cin >> set_size >> string_count;

    set<string> s;
    string tmp;
    for (int i = 0; i < set_size; i++)
    {
        cin >> tmp;
        s.insert(tmp);
    }

    int count = 0;
    for (int i = 0; i < string_count; i++)
    {
        cin >> tmp;
        if (s.end() != s.find(tmp))
            count++;
    }

    cout << count;
}