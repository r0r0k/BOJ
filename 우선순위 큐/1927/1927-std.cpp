#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    priority_queue<int, vector<int>, greater<int>> heap;

    int op;
    while (n--)
    {
        cin >> op;
        if (op == 0)
        {
            if (heap.size() == 0)
                cout << "0" << '\n';
            else
            {
                cout << heap.top() << '\n';
                heap.pop();
            }
        }
        else
            heap.push(op);
    }

    return 0;
}