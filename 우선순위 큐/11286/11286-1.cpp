#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n;

class Heap
{
private:
    int size;
    int *element;

public:
    Heap(int capacity)
    {
        size = 0;
        element = new int[capacity + 1];
    }

    ~Heap()
    {
        delete[] element;
    }

    int getSize()
    {
        return size;
    }

    void push(int val)
    {
        int i = ++size;
        while (i > 1)
        {
            if (abs(element[i / 2]) < abs(val))
                break;
            else if (abs(element[i / 2]) == abs(val) && element[i / 2] < val)
                break;
            else
            {
                element[i] = element[i / 2];
                i /= 2;
            }
        }
        element[i] = val;
    }

    int pop()
    {
        int res = element[1];
        int last_element = element[size--];
        int i = 1, child = 2 * i;

        while (2 * i <= size)
        {
            child = 2 * i;
            if (child < size)
            {
                if (abs(element[child]) > abs(element[child + 1]))
                    child++;
                else if (abs(element[child]) == abs(element[child + 1]) && element[child] > element[child + 1])
                    child++;
            }
            if (abs(element[child]) < abs(last_element))
                element[i] = element[child];
            else if (abs(element[child]) == abs(last_element) && element[child] < last_element)
                element[i] = element[child];
            else
                break;

            i = child;
        }
        element[i] = last_element;
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    Heap heap = Heap(n);

    int op;
    while (n--)
    {
        cin >> op;
        if (op == 0)
        {
            if (heap.getSize() == 0)
                cout << "0" << '\n';
            else
            {
                cout << heap.pop() << '\n';
            }
        }
        else
            heap.push(op);
    }

    return 0;
}