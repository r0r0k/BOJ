#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n;

struct cmp
{
    bool operator()(int a, int b) // b가 top
    {
        if (abs(a) == abs(b)) // 절댓값이 같다면
            return a > b;     // 실제 값이 작은게 top
        else
            return abs(a) > abs(b); // 절댓값이 다르면 절댓값이 작은게 top
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    priority_queue<int, vector<int>, cmp> heap;

    int op;
    while (n--)
    {
        cin >> op;
        if (op == 0)
        {
            if (heap.empty())
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