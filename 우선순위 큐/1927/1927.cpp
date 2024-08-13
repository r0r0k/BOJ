#include <iostream>
using namespace std;

int n;

// push : O(logn), pop : O(logn)
class MinHeap
{
private:
    int size;
    int *element; // tree 이므로 1-index

public:
    MinHeap(int capacity)
    {
        element = new int[capacity + 1]; // 1-index이기 때문
        size = 0;
    }
    ~MinHeap()
    {
        delete[] element;
    }

    void push(int val)
    {
        size++;
        int i = size;
        while (i > 1 && element[i / 2] > val)
        {
            element[i] = element[i / 2];
            i /= 2;
        }
        element[i] = val;
    }

    int pop()
    {
        int res = element[1];
        int last_element = element[size--];
        // return하기 전에 size--를 해주지 않고, 여기서 size--를 해줘도 상관 없는 이유는
        // 어쩌피 size--를 나중에 해서 첫번째 if에 걸리던 여기서 해서 첫번째 if에 걸리지 않던
        // 두번째 if에서 leaf에 대해서는 판단이 가능하기 때문임 (size--를 해주면 element[child] == last_element가 되어서 break로 탈출 후 last_element가 바로 올라감)
        int i = 1, child;

        while (2 * i <= size)
        {
            child = 2 * i;
            if (child < size && element[child] > element[child + 1])
                child++;

            if (element[child] < last_element)
                element[i] = element[child];

            else
                break;

            i = child;
        }
        element[i] = last_element;
        return res;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    MinHeap heap = MinHeap(n);

    int op;
    while (n--)
    {
        cin >> op;
        if (op == 0)
        {
            if (heap.getSize() == 0)
                cout << "0" << '\n';
            else
                cout << heap.pop() << '\n';
        }

        else
            heap.push(op);
    }

    return 0;
}