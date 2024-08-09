#include <iostream>
#include <set>
using namespace std;

int n;
set<int> s;

// 입력 범위가 1 ~ 20으로 정해져있어서 bool 배열을 사용해서 존재하는지 안하는지 0, 1로 표현해서 해도 됨
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    string op;
    int num;
    while (n--)
    {
        cin >> op;
        if (op == "add")
        {
            cin >> num;
            s.insert(num);
        }

        if (op == "remove")
        {
            cin >> num;
            s.erase(num);
        }

        if (op == "check")
        {
            cin >> num;
            if (s.find(num) == s.end())
                cout << "0" << '\n';
            else
                cout << "1" << '\n';
        }

        if (op == "toggle")
        {
            cin >> num;
            if (s.find(num) == s.end())
                s.insert(num);
            else
                s.erase(num);
        }

        if (op == "all")
        {
            for (int i = 1; i <= 20; i++)
                s.insert(i);
        }

        if (op == "empty")
        {
            s.clear();
        }
    }

    return 0;
}