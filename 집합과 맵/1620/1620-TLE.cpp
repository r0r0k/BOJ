#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 선형 탐색 시간 초과
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> vec(N);

    for (int i = 0; i < N; i++)
        cin >> vec[i];

    // sort(vec.begin(), vec.end());
    string tmp;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        if (tmp[0] > '0' && tmp[0] <= '9')
            cout << vec[stoi(tmp) - 1] << '\n';
        else
            // sort 후 lower_bound로 이진 탐색을 하면 index가 바뀌어서 도감 번호 찾기 불가능
            // cout << distance(vec.begin(), lower_bound(vec.begin(), vec.end(), tmp)) + 1 << '\n';
            cout << find(vec.begin(), vec.end(), tmp) - vec.begin() + 1 << '\n';
    }
}