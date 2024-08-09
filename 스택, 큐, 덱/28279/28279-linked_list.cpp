#include <iostream>

using namespace std;

// 1 X  : push_front
// 2 x  : push_back
// 3    : pop_front
// 4    : pop_back
// 5    : size
// 6    : empty
// 7    : front
// 8    : back

template <typename T>
struct Node
{
    Node<T> *prev;
    Node<T> *next;
    T value;
};

template <typename T>
class Deque
{
private:
    Node<T> *header; // c와 달리 struct를 안붙여도 됨
    Node<T> *tail;
    int size_;

public:
    Deque()
    {
        header = nullptr;
        tail = nullptr;
        size_ = 0;
    }

    ~Deque()
    {
        while (header != nullptr)
        {
            Node<T> *tmp = header;
            if (header->next != nullptr)
            {
                header = header->next;
                delete tmp;
            }
            else
            {
                delete tmp;
                header = nullptr;
            }
        }
    }

    void push_front(int val)
    {
        Node<T> *node = new Node<T>; // 동적할당을 안하면 push_front가 끝나는 순간 바로 메모리에서 해제되서 유지 안됨
        node->prev = nullptr;
        node->value = val;

        if (size_ == 0)
        {
            node->next = nullptr;
            header = node;
            tail = node;
        }

        else
        {
            node->next = header;
            header->prev = node;
            header = node;
        }
        size_++;
    }

    void push_back(int val)
    {

        Node<T> *node = new Node<T>;
        node->next = nullptr;
        node->value = val;

        if (size_ == 0)
        {
            node->prev = nullptr;
            header = node;
            tail = node;
        }

        else
        {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        size_++;
    }

    T pop_front()
    {
        if (empty())
            return -1;
        else
        {
            size_--;
            int val = header->value;

            Node<T> *tmp = header;
            header = header->next;
            header->prev = nullptr;
            delete tmp;

            return val;
        }
    }

    T pop_back()
    {
        if (empty())
            return -1;
        else
        {
            size_--;
            int val = tail->value;

            Node<T> *tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete tmp;

            return val;
        }
    }

    int size()
    {
        return size_;
    }

    int empty()
    {
        return (size_ == 0);
    }

    T front()
    {
        if (empty())
            return -1;
        else
            return header->value;
    }

    T back()
    {
        if (empty())
            return -1;
        else
            return tail->value;
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