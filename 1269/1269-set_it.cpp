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

    // vector 대신 set을 쓰면 sort는 안해줘도 되지만, set은 이진 트리로 구현되어 있기 때문에 map과 vector와 달리 index로 접근 불가능
    // 따라서 set의 경우에는 iterator로 접근해야함
    // vector 대신 set을 쓰면, set은 요소의 중복이 허용되지 않아서 중복 처리가 가능하므로 좋음
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    int s1_size = s1.size();
    int s2_size = s2.size();
    int count = 0;

    while (it1 != s1.end() && it2 != s2.end())
    {
        if (*it1 == *it2)
        {
            it1++;
            it2++;
        }

        else if (*it1 < *it2)
        {
            count++;
            it1++;
        }

        else if (*it1 > *it2)
        {
            count++;
            it2++;
        }
    }

    // s1, s2 중 어떤 set이 먼저 끝났을지 모르니 둘다 빼줌 (먼저 끝난건 어쩌피 0이 더해지므로 상관 X)
    // 그리고 s1.end() - it1이 안되는 이유 또한, set자체가 이진 트리로 구현되어 있기 때문에 vector와 달리 iterator의 뺄셈이 불가능해서 distance를 써야함
    count += distance(it1, s1.end());
    count += distance(it2, s2.end());

    cout << count;
}