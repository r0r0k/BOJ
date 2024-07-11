```
// 10815번

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool binary_search(vector<int> &vec, int target)
{
    int begin = 0;
    int end = vec.size() - 1;
    int mid;

    while (begin <= end)
    {
        mid = (begin + end) / 2;
        if (vec[mid] == target)
            return true;
        else if (vec[mid] < target)
            begin = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}

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

    vector<int>::iterator it;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        it = lower_bound(vec.begin(), vec.end(), tmp);
        // 여기서 lower_bound를 못찾아서 vec.end()가 return되는 경우 distance로 index에 접근 못하기 때문에 오류 발생
        // 따라서 lower_bound가 vec.end()일 때는 바로 0을 출력해주면 됨
        if (it == vec.end())
            cout << "0 ";
        else
            cout << (tmp == vec[distance(vec.begin(), it)]) << " ";

        // 2. binary search 구현
        // cout << binary_search(vec, tmp) << " ";

        // 3. binary_search 라이브러리
        // cout << binary_search(vec.begin(), vec.end(), tmp) << " ";
    }

    // 아래 방법으로 선형 탐색을 하면 시간 초과 발생
    // for (int i = 0; i < count; i++)
    // {
    //     cin >> tmp;
    //     cout << (vec.end() != find(vec.begin(), vec.end(), tmp)) << " ";
    // }
}
```