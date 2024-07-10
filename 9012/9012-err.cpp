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
        this->size--;
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

    char tmp;

    while (count--)
    {
        s = new Stack;
        cin >> tmp;
        while (tmp != '\n') // cin >> tmp는 '\n'을 무시하므로 이렇게 받을 수 없음
        {
            if (tmp == '(')
                s->insert(tmp);

            else if (tmp == ')')
            {
                if (s->is_empty())
                {
                    // 이렇게 해버리면 break 후 아래에서 s->is_empty()가 한번 더 걸려서 YES가 되고 남은 tmp도 못받아와서 외부 while 문을 계속 돌게 됨
                    // cout << "NO\n";
                    // break;

                    s->insert(tmp); // 아예 그냥 ')'를 넣어버려서 is_empty()에 걸릴 수 없게 하면 됨
                }
                else if (s->front() == '(')
                    s->pop();
                else
                    s->insert(tmp);
            }

            cin >> tmp;
        }

        if (s->is_empty())
            cout << "YES\n";
        else
            cout << "NO\n";

        delete s;
    }
}