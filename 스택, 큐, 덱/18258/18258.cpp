#include <iostream>
#define MAXSIZE 2000000

using namespace std;

class Queue
{
private:
    int front_;
    int rear;
    int queue_size;
    int *queue;

public:
    Queue()
    {
        front_ = 0;
        rear = 0;
        queue_size = 0;
        // size 변수 없이 is_empty를 체크하려면, MAXSIZE + 1만큼 배열을 선언해줘야함 (index 0은 비워야 하므로)
        // empty : front == rear
        // full  : front == (rear + 1) % (MAXSIZE + 1)
        // 그래서 그냥 queue_size 선언해서 쓰자
        queue = new int[MAXSIZE];
    }

    ~Queue()
    {
        delete[] queue;
    }

    void push(int val)
    {
        queue[rear] = val;
        rear = (rear + 1) % MAXSIZE;
        queue_size++;
    }

    int pop()
    {
        if (empty())
            return -1;
        else
        {
            int val = queue[front_];
            front_ = (front_ + 1) % MAXSIZE;
            queue_size--;
            return val;
        }
    }

    int size()
    {
        return queue_size;
        // return (rear - front_ + MAXSIZE) % MAXSIZE;
    }

    int empty()
    {
        return (queue_size == 0);
    }

    int full()
    {
        return (queue_size == MAXSIZE);
    }

    int front()
    {
        if (empty())
            return -1;
        else
            return queue[front_];
    }

    int back()
    {
        if (empty())
            return -1;
        else
            return queue[rear - 1]; // rear은 다음에 push할 index를 가리키기 때문에 back은 (rear -1)의 index를 return 해야함
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    Queue q;
    string ins;
    int val;
    while (count--)
    {
        cin >> ins;
        if (ins == "push")
        {
            cin >> val;
            q.push(val);
        }

        else if (ins == "pop")
            cout << q.pop() << "\n";

        else if (ins == "size")
            cout << q.size() << "\n";

        else if (ins == "empty")
            cout << q.empty() << "\n";

        else if (ins == "front")
            cout << q.front() << "\n";

        else if (ins == "back")
            cout << q.back() << "\n";
    }
}