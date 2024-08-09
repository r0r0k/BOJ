#include <iostream>
#include <vector>

using namespace std;

// 1 X  : insert X
// 2    : pop 후 출력, 없다면 -1 출력
// 3    : size
// 4    : is_empty (비어있으면 1, 아니면 0)
// 5    : front 출력, 없다면 -1 출력

class Stack
{
private:
    int size;
    vector<int> stack; // 크기가 정해지지 않았기 때문에 vector로 구현

public:
    Stack()
    {
        this->size = 0;
    }

    void insert(int val) // 1
    {
        this->stack.push_back(val);
        this->size++;
    }

    int pop() // 2
    {
        if (this->size == 0)
            return -1;
        // else
        // {
        //     return this->stack[--this->size];
        // }
        // 위 처럼 하면 array면 가능하지만 vector는 push_back을 하므로 새로운 insert가 size에 따라 안 쌓이고 뒤로 쌓여서 오류가 남
        else
        {
            int val = this->stack.back();
            // int val = front();
            this->stack.pop_back(); // 이걸 안해주면 위 코드를 돌렸을때 통과를 안함
            this->size--;
            return val;
        }
    }

    int get_size() // 3
    {
        return this->size;
    }

    int is_empty() // 4
    {
        return this->size == 0;
    }

    int front() // 5
    {
        if (this->size == 0)
            return -1;
        else
            return this->stack[this->size - 1];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    Stack s; // 생성자가 private이면 선언 불가
    int ins_num;
    int insert_val;

    while (count--)
    {
        cin >> ins_num;

        switch (ins_num)
        {
        case 1:
            cin >> insert_val;
            s.insert(insert_val);
            break;
        case 2:
            cout << s.pop() << '\n';
            break;
        case 3:
            cout << s.get_size() << '\n';
            break;
        case 4:
            cout << s.is_empty() << '\n';
            break;
        case 5:
            cout << s.front() << '\n';
            break;
        }
    }
}