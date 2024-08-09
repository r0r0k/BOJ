#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<string, int> type_cnt;
int res = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int size;
    string name, type; // 의상의 이름, 의상의 종류
    while (n--)
    {
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            cin >> name >> type;
            type_cnt[type]++;
        }

        for (auto it : type_cnt)
            res *= it.second + 1;

        cout << res - 1 << '\n';
        res = 1;
        type_cnt.clear();
    }

    return 0;
}