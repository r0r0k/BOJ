#include <iostream>
#include <deque>

using namespace std;

// 1 X  : push_front
// 2 x  : push_back
// 3    : pop_front
// 4    : pop_back
// 5    : size
// 6    : empty
// 7    : front
// 8    : back

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    deque<int> d;

    int ins_num;
    int val;

    while (count--)
    {
        cin >> ins_num;

        switch (ins_num)
        {
        case 1:
            cin >> val;
            d.push_front(val);
            break;

        case 2:
            cin >> val;
            d.push_back(val);
            break;

        case 3:
            if (d.empty())
                cout << "-1";
            else
            {
                cout << d.front();
                d.pop_front();
            }
            cout << '\n';
            break;

        case 4:
            if (d.empty())
                cout << "-1";
            else
            {
                cout << d.back();
                d.pop_back();
            }
            cout << '\n';
            break;

        case 5:
            cout << d.size();
            cout << '\n';
            break;

        case 6:
            cout << d.empty();
            cout << '\n';
            break;

        case 7:
            if (d.empty())
                cout << "-1";
            else
                cout << d.front();
            cout << '\n';
            break;

        case 8:
            if (d.empty())
                cout << "-1";
            else
                cout << d.back();
            cout << '\n';
            break;
        }
    }
}