#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    map<int, int> m;

    int tmp;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        // insert는 기존에 key가 존재하는 경우 아무 수행도 하지 않고 pair<itertor, bool>에서 bool == false를 return함
        // 따라서 처음 넣는 경우는 알아서 1이 들어갈 것이고, 두번째 넣는 경우 insert가 실패하므로 그때되서 key로 접근해서 value++을 해주면 됨
        // pair<map<int, int>::iterator, bool> ret = m.insert(make_pair(tmp, 1));
        auto ret = m.insert(make_pair(tmp, 1));
        if (ret.second == false)
            m[tmp]++; // 사실 c++에서는 map에 key를 처음 넣을 때, 알아서 0으로 초기화되므로 이 코드 하나만 있어도 되긴 함
    }

    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        cout << m[tmp] << " ";
    }
}