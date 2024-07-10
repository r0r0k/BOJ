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

// 1. vector에 입력 전부 받기
// 2. vector의 요소에 반복문을 돌며 stack의 front에 대해 반복문으로 계속 현재 turn이 나오면 pop해줌
// 여기서 if가 아닌 while로 계속 빼주지 않으면 stack 안에 이후에도 번호 순서가 있는데 안빠져나가고 vector가 stack에 들어가버림
// 3. stack에 현재 턴이 더이상 존재하지 않으면 vector의 요소가 현재 턴인지 확인 후 현재 턴이면 turn을 증가
// 4. 둘다 아닌 경우 stack에 insert
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size;
    cin >> size;

    Stack s;
    vector<int> vec(size);
    for (int i = 0; i < size; i++)
        cin >> vec[i];

    int turn = 1;
    for (auto it : vec)
    {
        // stack 먼저 검사해줘야함 : vector 기준으로 for문을 순회하기 때문
        // while 대신 if를 쓰면 stack 안에 제 차례인 순서가 남아있더라도 뛰어넘어버림
        while (!s.is_empty() && s.front() == turn)
        {
            s.pop();
            turn++;
        }

        if (it == turn)
            turn++;
        else
            s.insert(it);
    }

    while (!s.is_empty())
    {
        if (s.front() == turn)
        {
            s.pop();
            turn++;
        }
        else // front가 turn이 아닌 경우, 더이상 stack에서 남은게 빠져나올 수 없기 때문에 바로 Sad 출력 후 break
        {
            cout << "Sad";
            break;
        }
    }

    if (s.is_empty()) // while으로 정상적으로 탈출했다면 stack이 비어있기 때문에 Nice 출력
        cout << "Nice";
}
