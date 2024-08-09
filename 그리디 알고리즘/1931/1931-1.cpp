#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n;
vector<pair<unsigned, unsigned>> vec; // 회의 시작 시간과 소요 시간을 저장하는 배열

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
        vec.push_back({end, start});
    }

    sort(vec.begin(), vec.end());

    int cur = 0;
    int count = 0;

    for (auto it : vec)
    {
        if (it.second >= cur)
        {
            count++;
            cur = it.first;
        }
    }

    cout << count;

    return 0;
}