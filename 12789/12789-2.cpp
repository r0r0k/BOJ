#include <iostream>
#include <vector>

using namespace std;

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

    void insert(int val)
    {
        this->stack.push_back(val);
        this->size++;
    }

    void pop()
    {
        this->size--;
        stack.pop_back();
    }

    int get_size()
    {
        return this->size;
    }

    int is_empty()
    {
        return this->size == 0;
    }

    int front()
    {
        return this->stack[this->size - 1]; // main에서 is_empty가 아닐때만 front를 호출하므로 is_empty 조건은 여기서 확인 안했음
    }
};

// 1. size만큼 입력을 받으며, stack의 front에 대해 반복문으로 계속 현재 turn이 나오면 pop해줌
// 여기서 if가 아닌 while로 계속 빼주지 않으면 stack 안에 이후에도 번호 순서가 있는데 안빠져나가고 vector가 stack에 들어가버림
// 2. stack에 현재 턴이 더이상 존재하지 않으면 입력 받은 값이 turn과 같은지 확인 후 같다면 turn++
// 3. 둘다 아닌 경우 stack에 insert

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size;
    cin >> size;

    Stack s;
    int tmp;
    int turn = 1;
    while (size--)
    {
        while (!s.is_empty() && s.front() == turn)
        {
            s.pop();
            turn++;
        }

        cin >> tmp;
        if (tmp == turn)
            turn++;
        else
            s.insert(tmp);
    }

    while (!s.is_empty() && s.front() == turn)
    {
        s.pop();
        turn++;
    }

    if (s.is_empty())
        cout << "Nice";
    else
        cout << "Sad";
}
