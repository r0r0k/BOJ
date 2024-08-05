#include <iostream>
#include <map>
using namespace std;

int N, M;
map<string, string> m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    string site_name;
    string password;

    while (N--)
    {
        cin >> site_name >> password;
        m[site_name] = password;
    }

    while (M--)
    {
        cin >> site_name;
        cout << m[site_name] << '\n';
    }

    return 0;
}