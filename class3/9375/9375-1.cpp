#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n;
int cnt = 0;
string type_arr[30]; // 의상의 종류
unordered_set<string> is_used;

void bt(int cur, int size)
{
    for (int i = cur; i < size; i++)
    {
        if (is_used.insert(type_arr[i]).second != false) // is_used에 해당 의상 종류가 존재하지 않는 경우
        {
            cnt++;
            bt(i + 1, size);
            is_used.erase(type_arr[i]);
        }
    }
}

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
            type_arr[i] = type;
        }

        bt(0, size);

        cout << cnt << '\n';
        cnt = 0;
    }

    return 0;
}