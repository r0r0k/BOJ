#include <iostream>
#include <map>

using namespace std;

struct cmp
{
    bool operator()(const string &a, const string &b) const
    {
        return a > b;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    string name;
    string history;

    // map이나 set은 기본적으로 오름차순 정렬임
    // 내림차순으로 정렬하려면 greater<>를 쓰거나 cmp struct를 새로 만들어줘야함
    map<string, bool, cmp> m;
    // map<string, bool, greater<>> m;
    for (int i = 0; i < count; i++)
    {
        cin >> name >> history;
        if (history == "enter")
        {
            // m.insert(make_pair(name, true));
            // 이렇게 하면 같은 키가 2번 insert되므로 enter가 다시 되어도 아무런 수행을 안해서 true로 안변함
            // insert를 하려면 else에 erase를 해줘야함
            // insert는 성공 여부를 알고 싶을 때 사용
            m[name] = true;
            // set은 insert만 가능
        }
        else
        {
            m[name] = false;
            // m.erase(name);
        }
    }

    for (auto it : m)
        if (it.second == true)
            cout << it.first << "\n";
}