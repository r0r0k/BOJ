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
    for (int i = 0; i < count; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end()); // lower_bound는 이진 탐색을 하기 때문에 vector가 정렬되어 있어야 함

    cin >> count;
    int tmp;

    // lower_bound, distance 함수로 이진 탐색
    vector<int>::iterator it;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;

        // 1. lower_bound - vec.begin() 사용
        // if (lower_bound(vec.begin(), vec.end(), tmp) == vec.end())
        //     cout << "0 ";
        // else
        //     cout << (tmp == vec[lower_bound(vec.begin(), vec.end(), tmp) - vec.begin()]) << " ";

        // 2. upper_bound - lower_bound 사용
        // cout << upper_bound(vec.begin(), vec.end(), tmp) - lower_bound(vec.begin(), vec.end(), tmp) << " ";

        // 3. lower_bound, distance 사용
        it = lower_bound(vec.begin(), vec.end(), tmp);

        // 여기서 lower_bound를 못찾아서 vec.end()가 return 되는 경우 distance로 index에 접근 못하기 때문에 오류 발생
        // 따라서 lower_bound가 vec.end()일 때는 바로 0을 출력해주면 됨
        if (it == vec.end())
            cout << "0 ";
        else
            cout << (tmp == vec[distance(vec.begin(), it)]) << " ";
    }

    // 4. 선형 탐색 -> TLE
    // for (int i = 0; i < count; i++)
    // {
    //     cin >> tmp;
    //     cout << (vec.end() != find(vec.begin(), vec.end(), tmp)) << " ";
    // }
}