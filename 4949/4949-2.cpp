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

    // cin >> str; 은 공백이 들어오면 짤리므로, 한줄 전체를 str에 받기 위해서는 getline을 사용해야함
    while (getline(cin, str))
    {
        if (str[0] == '.')
            break;

        s = new Stack;
        for (auto ch : str)
        {
            if (ch == '(')
                s->insert(ch);

            else if (ch == ')')
            {
                if (!s->is_empty() && s->front() == '(')
                    s->pop();

                else
                    s->insert(ch);
            }

            else if (ch == '[')
                s->insert(ch);

            else if (ch == ']')
            {
                if (!s->is_empty() && s->front() == '[')
                    s->pop();

                else
                    s->insert(ch);
            }
        }

        if (s->is_empty())
            cout << "yes\n";
        else
            cout << "no\n";

        delete s;
    }
}