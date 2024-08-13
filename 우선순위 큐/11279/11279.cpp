#include <iostream>
using namespace std;

int n;

// push : O(logn), pop : O(logn)
class MaxHeap
{
private:
    int size;
    int *element; // tree 이므로 1-index

public:
    MaxHeap(int capacity)
    {
        element = new int[capacity + 1]; // 1-index이기 때문
        size = 0;
    }
    ~MaxHeap()
    {
        delete[] element;
    }

    void push(int val)
    {
        size++;
        int i = size;
        while (i > 1 && element[i / 2] < val) // i > 1인 조건이 있어야만 size가 1일때와 (i / 2)가 0이 되는 segfault를 처리 가능
        {
            element[i] = element[i / 2];
            i /= 2;
        }
        element[i] = val;
    }

    int pop()
    {
        int max = element[1];
        int last_element = element[size--];
        int child;
        int i = 1;

        while (2 * i <= size) // left 바로 위의 노드까지 탐색 : 여기선 size보다 같거나 작도록 해야함 (leaf 노드가 1개여도 두번째 if로 판단해야 하기 때문에)
        {
            child = 2 * i;
            if (child < size && element[child] < element[child + 1]) // child <= size로 하면 child + 1에서 segfault가 발생
                child++;

            if (element[child] > last_element) // height 차이가 2부터는 무조건 element[child]가 더 커서 break에 안걸림
                element[i] = element[child];

            else
                break; // 아래의 i = child를 수행 X

            i = child;
        }
        element[i] = last_element;

        return max;
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
    MaxHeap heap = MaxHeap(n);

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