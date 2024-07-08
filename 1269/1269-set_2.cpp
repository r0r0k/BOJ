#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size1, size2;
    cin >> size1 >> size2;

    set<int> s1;
    set<int> s2;

    int tmp;
    for (int i = 0; i < size1; i++)
    {
        cin >> tmp;
        s1.insert(tmp);
    }

    for (int i = 0; i < size2; i++)
    {
        cin >> tmp;
        s2.insert(tmp);
    }

    int count = 0;

    // set_it 방식보다 약간 더 느림 : set_it은 s1, s2를 동시에 순회하며 한쪽이 끝나면 나머지는 순회할 필요가 없기 때문
    for (auto it : s1)
        if (s2.find(it) == s2.end())
            count++;

    for (auto it : s2)
        if (s1.find(it) == s1.end())
            count++;

    cout << count;
}