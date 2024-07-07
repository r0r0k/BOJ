#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    vector<int> vec(count);

    int tmp;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        vec[i] = tmp;
    }

    sort(vec.begin(), vec.end());

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        auto lb = lower_bound(vec.begin(), vec.end(), tmp); // lb는 >= tmp가 (tmp 이상) 처음 나오는 iterator를 return
        auto ub = upper_bound(vec.begin(), vec.end(), tmp); // lb는 > tmp가 (tmp 초과) 처음 나오는 iterator를 return
        // 만약에 tmp가 없으면 ub, lb 둘다 vec.end()나 tmp를 초과하는 iterator를 가리키므로 0을 출력해서 lb != vec.end() 를 해주지 않아도 됨
        // 10815에서는 lower_bound만 사용하였기 때문에 카드가 존재하지 않는 경우 vec.end()를 가리키므로 체크해줬어야함
        cout << ub - lb << " ";
    }
}