#include <iostream>
#include <vector>

using namespace std;

// '(' 입력시 무조건 insert
// ')' 입력시 stack이 비어있으면 바로 NO 출력, front가 '(' 이면 insert 하지 않고 pop
// 입력 받은 string 처리가 끝난 후 stack이 비어있고 위에서 NO를 출력하지 않았으면 YES 출력, stack이 비어있지 않고 위에서 NO를 출력하지 않았으면 NO 출력

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
        this->size--; // main에서 is_empty가 아닐때만 pop을 호출하므로 is_empty 조건은 여기서 확인 안했음
        stack.pop_back();
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    Stack *s;
    string tmp;
    bool no_flag; // 앞에서 NO를 출력했는지 확인하기 위해

    while (count--)
    {
        no_flag = false;
        s = new Stack;
        cin >> tmp;

        for (char ch : tmp) // cin >> tmp는 '\n'을 건너뛰므로 char 자체로 개행문자를 확인할 수 없음 : string으로 입력받아야함
        {
            if (ch == '(')
                s->insert(ch);

            else if (ch == ')')
            {
                // 뒤에서 front를 검사하므로 무조건 앞에서 is_empty를 먼저 검사해줘야함, 아니면 segmentation fault남
                if (s->is_empty())
                {
                    cout << "NO\n";
                    no_flag = true;
                    break;
                }
                else if (s->front() == '(')
                    s->pop();

                // else if (s->front() == ')') 인 상황은 있을 수 없음
                // ')'는 1. front가 '(' 일 때 pop을 하거나
                // 2. empty일 경우 NO만 출력하므로 insert 되서 stack에 연속으로 ')'가 있는 경우가 없기 때문
            }
        }

        if (!no_flag) // 앞에서 NO를 출력하지 않은 경우
        {
            if (s->is_empty())
                cout << "YES\n";
            else
                cout << "NO\n";
        }

        delete s;
    }
}