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
        s = new Stack;
        cin >> tmp;

        for (char ch : tmp) // cin >> tmp는 '\n'을 건너뛰므로 char 자체로 개행문자를 확인할 수 없음 : string으로 입력받아야함
        {
            if (ch == '(')
                s->insert(ch);

            else if (ch == ')')
            {
                // front를 검사하기 전에 무조건 is_empty 부터 검사해줘야함, 아니면 segmentation fault남
                // && 좌우 순서 거꾸로 쓰면 front부터 하므로 똑같이 segmentation fault남
                if (!s->is_empty() && s->front() == '(')
                    s->pop();

                else
                    s->insert(ch);

                // if (s->is_empty())
                //     s->insert(ch);

                // else if (s->front() == '(')
                //     s->pop();

                // else
                //     s->insert(ch);
            }
        }

        if (s->is_empty())
            cout << "YES\n";
        else
            cout << "NO\n";

        delete s;
    }
}