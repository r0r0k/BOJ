#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size1, size2;
    cin >> size1 >> size2;

    map<int, int> m; // A, B의 합집합을 저장할 map : value는 입력으로 들어온 해당 원소의 수

    int tmp;
    for (int i = 0; i < size1; i++)
    {
        cin >> tmp;
        m[tmp]++; // insert, erase 방법은 중복이 없을때만 가능함
    }

    for (int i = 0; i < size2; i++)
    {
        cin >> tmp;
        m[tmp]++;
    }

    int count = m.size();

    for (auto it : m)
        if (it.second == 2) // 2번 들어온 경우 교집합이므로 교집합인 경우 빼줌 : 대칭 차집합은 두 집합의 교집합을 뺀 것이므로
            count--;

    // 중복이 없을 경우만 아래처럼 가능, 중복이 있다면 count가 2번 빠지므로 이거 못씀 (insert, erase도 마찬가지로 중복시 insert->erase->insert가 되므로 안됨)
    // int count = 0;
    // for (int i = 0; i < size2; i++)
    // {
    //     cin >> tmp;
    //     m[tmp]++;

    //     if (m[tmp] == 2)
    //         count--;
    // }

    // count += m.size();

    cout << count;
}