#include <iostream>
#include <set>

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
    set<string, cmp> s;
    // set<string, greater<>> s;
    for (int i = 0; i < count; i++)
    {
        cin >> name >> history;
        if (history == "enter")
            s.insert(name);
        else
            s.erase(name);
    }

    for (auto it : s)
        cout << it << "\n";
}