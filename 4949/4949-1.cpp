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

    Stack *s;
    string str;
    char tmp;

    // '.' 이 처음에 들어왔다면 프로그램을 종료시키기 위해 판단하는 변수 설정
    int end_count;
    bool end_flag = false;

    while (1)
    {
        str = "";
        end_count = 0;

        // line별로 입력이 들어오지 않고 '.'으로 구분되어 들어오는 경우 getline으로 불가능하기 때문에 아래처럼 해야함
        // 사실 쭉 들어와서 개행문자가 없다고 가정하면 되지만, 4949번에서는 개행문자가 존재하는데,
        // cin.get 으로 받으면 cin >> 와 달리 개행문자도 받기 때문에 제대로 end_count를 확인하기 위해 개행 문자가 처음(맨앞에서) 들어올 경우 아무 동작을 하지 않아야 함
        while (cin.get(tmp))
        {
            if (tmp == '\n')
                continue;

            if (tmp == '.')
            {
                if (end_count == 0) // 바로 '.' 이 들어온 경우
                    end_flag = true;
                break;
            }
            str += tmp;
            end_count++;
        }

        if (end_flag)
            break;

        s = new Stack;
        bool no_flag = false;

        for (auto ch : str)
        {
            if (ch == '(')
                s->insert(ch);

            else if (ch == ')')
            {
                if (s->is_empty() || s->front() == '[') // short-circuit evaluation 때문에 어쩌피 empty면 뒤에 front 안함
                {
                    no_flag = true;
                    cout << "no\n";
                    break;
                }

                else
                    s->pop();
            }

            else if (ch == '[')
                s->insert(ch);

            else if (ch == ']')
            {
                if (s->is_empty() || s->front() == '(')
                {
                    no_flag = true;
                    cout << "no\n";
                    break;
                }

                else
                    s->pop();
            }
        }

        if (!no_flag)
        {
            if (s->is_empty())
                cout << "yes\n";
            else
                cout << "no\n";
        }

        delete s;
    }
}