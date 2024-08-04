#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n;
vector<pair<unsigned, unsigned>> vec; // 회의 시작 시간과 소요 시간을 저장하는 배열

// end를 기준으로 오름차순으로 저장
bool cmp(pair<unsigned, unsigned> a, pair<unsigned, unsigned> b)
{
    // end를 기준으로 오름차순으로 정렬해야하는데, end가 같은 경우 start를 기준으로 오름차순으로 정렬해야함
    // 해당 조건을 써주지 않으면 [2 4] [3 4] [4 4] 의 경우, [2 4]부터 선택되야 하는데 [4 4]부터 선택되므로 안됨
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    unsigned start, end;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        vec.push_back({start, end});
    }

    sort(vec.begin(), vec.end(), cmp);

    int cur = 0;
    int count = 0;

    for (auto it : vec)
    {
        if (it.first >= cur)
        {
            count++;
            cur = it.second;
        }
    }

    cout << count;

    return 0;
}