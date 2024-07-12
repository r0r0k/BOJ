#include <iostream>
#include <vector>
#define MAXSIZE 1000000

using namespace std;

// 1 X  : push_front
// 2 x  : push_back
// 3    : pop_front
// 4    : pop_back
// 5    : size
// 6    : empty
// 7    : front
// 8    : back

// 원형 덱 구현
template <typename T>
class Deque
{
private:
    int _front;
    int _rear;
    int _size;
    T *arr;

public:
    Deque()
    {
        _front = 0; // 현재 front를 가리킴
        _rear = 0;  // 현재 (back + 1) 을 가리킴 : 미래에 push_back()할 곳
        _size = 0;
        arr = new T[MAXSIZE];
    }

    ~Deque()
    {
        delete[] arr;
    }

    void push_front(T val)
    {
        if (_front == 0) // front가 0인 경우 -1을 하면 index가 -1이 되므로, (MAXSIZE - 1)로 index를 이동해서 원형 덱으로 구현해야함
            _front = MAXSIZE - 1;
        else
            _front--;

        // front는 현재 front를 가리켜야 하므로, front 연산을 미리 하고 그 자리에 val을 대입해야함
        arr[_front] = val;
        _size++;
    }

    void push_back(T val)
    {
        // _rear는 (back + 1)을 가리키므로, 먼저 val을 대입 후 rear 연산을 해줘야 함
        arr[_rear] = val;
        _rear = (_rear + 1) % MAXSIZE;
        _size++;
    }

    T pop_front()
    {
        if (empty())
            return -1;
        else
        {
            // 여기서 size가 1일 때, size--;를 먼저 하고 back을 부르니까 back에서 empty를 return해버림
            // _size--;
            // 항상 size 관련 변수는 is_empty가 있으니, 모든 대입을 다 끝낸 후 return 하기 바로 전 마지막에 update 해주자.

            T val = front();
            _front = (_front + 1) % MAXSIZE;
            _size--;
            return val;
        }
    }

    T pop_back()
    {
        if (empty())
            return -1;
        else
        {
            // 여기서 size가 1일 때, size--;를 먼저 하고 back을 부르니까 back에서 empty를 return해버림
            // _size--;
            // 항상 size 관련 변수는 is_empty가 있으니, 모든 대입을 다 끝낸 후 return 하기 바로 전 마지막에 update 해주자.

            T val = back();

            if (_rear == 0)
                _rear = MAXSIZE - 1;
            else
                _rear--;

            _size--;
            return val;
        }
    }

    int size()
    {
        return _size;
    }

    int empty()
    {
        return (_size == 0);
    }

    T front()
    {
        if (empty())
            return -1;
        else
            return arr[_front];
    }

    T back()
    {
        if (empty())
            return -1;

        else if (_rear == 0)
            return arr[MAXSIZE - 1];

        else
            return arr[_rear - 1];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    Deque<int> deque;

    int ins_num;
    int val;

    while (count--)
    {
        cin >> ins_num;

        switch (ins_num)
        {
        case 1:
            cin >> val;
            deque.push_front(val);
            break;

        case 2:
            cin >> val;
            deque.push_back(val);
            break;

        case 3:
            cout << deque.pop_front();
            cout << '\n';
            break;

        case 4:
            cout << deque.pop_back();
            cout << '\n';
            break;

        case 5:
            cout << deque.size();
            cout << '\n';
            break;

        case 6:
            cout << deque.empty();
            cout << '\n';
            break;

        case 7:
            cout << deque.front();
            cout << '\n';
            break;

        case 8:
            cout << deque.back();
            cout << '\n';
            break;
        }
    }
}