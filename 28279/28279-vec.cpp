#include <iostream>
#include <vector>

using namespace std;

// 1 X  : push_front_val
// 2 x  : push_back_val
// 3    : pop_front_val
// 4    : pop_back_val
// 5    : size
// 6    : empty
// 7    : front
// 8    : back

template <typename T>
class Deque
{
private:
    // vector를 쓰면 erase에서 O(N)이므로 TLE가 남
    vector<T> vec;

public:
    void push_front_val(T val)
    {
        vec.insert(vec.begin(), val);
    }

    void push_back_val(T val)
    {
        vec.push_back(val);
    }

    T pop_front_val()
    {
        if (empty())
            return -1;
        else
        {
            int val = vec.front();
            vec.erase(vec.begin());
            return val;
        }
    }

    T pop_back_val()
    {
        if (empty())
            return -1;
        else
        {
            int val = vec[vec.size() - 1];
            vec.pop_back();
            return val;
        }
    }

    int size()
    {
        return vec.size();
    }

    int empty()
    {
        return (vec.size() == 0);
    }

    T front()
    {
        if (empty())
            return -1;
        else
            return vec.front();
    }

    T back()
    {
        if (empty())
            return -1;
        else
            return vec[vec.size() - 1];
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
            deque.push_front_val(val);
            break;

        case 2:
            cin >> val;
            deque.push_back_val(val);
            break;

        case 3:
            cout << deque.pop_front_val();
            cout << '\n';
            break;

        case 4:
            cout << deque.pop_back_val();
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