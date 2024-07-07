#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;

    cin >> N >> M;

    // 사실 vector로 binary search를 할거면 sort -> binary_search를 해야하니까 그냥 바로 sort되있어서 find로도 이진 탐색이 가능한 set쓰는게 낫긴함
    vector<string> vec(N);
    set<string> s; // 교집합을 저장할 set : 사전순 정렬을 위해 vector대신 set을 사용
    int count = 0;

    for (int i = 0; i < N; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    string tmp;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        if (binary_search(vec.begin(), vec.end(), tmp))
        {
            count++;
            s.insert(tmp);
        }
    }

    cout << count << '\n';
    for (auto it : s)
        cout << it << '\n';
}