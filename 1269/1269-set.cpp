#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size1, size2;
    cin >> size1 >> size2;

    set<int> s;

    int tmp;
    for (int i = 0; i < size1; i++)
    {
        cin >> tmp;
        s.insert(tmp);
    }

    int count = 0;
    for (int i = 0; i < size2; i++)
    {
        cin >> tmp;
        if (s.find(tmp) != s.end())
            count--; // 만약 입력받는 집합에 중복이 있었다면 이렇게 하면 안되고 map을 써야함
        else
            s.insert(tmp);
    }

    count += s.size();
    cout << count;
}