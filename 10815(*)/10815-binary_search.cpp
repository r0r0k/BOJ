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

    return false; // 반복문 탈출한 경우
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

        // 2. bisnary search 구현
        cout << binary_search(vec, tmp) << " ";

        // 3. binary_search 라이브러리
        // cout << binary_search(vec.begin(), vec.end(), tmp) << " ";
    }
}