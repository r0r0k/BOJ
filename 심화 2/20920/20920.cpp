#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) // 모든 경우에 return 붙여줘야 하는거 기억하기
{
    if (a.second > b.second)
        return true;

    else if (a.second == b.second)
    {
        if (a.first.length() > b.first.length())
            return true;
        else if (a.first.length() == b.first.length())
            return a.first < b.first;
        else
            return false;
    }

    else
        return false;
}

// bool cmp(const pair<string, int> &a, const pair<string, int> &b) // 모든 경우에 return 붙여줘야 하는거 기억하기
// {

//     if (a.second == b.second)
//     {
//         if (a.first.length() == b.first.length())
//             return a.first < b.first;
//         return a.first.length() > b.first.length();
//     }
//     return a.second > b.second;
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count, limit;
    cin >> count >> limit;

    map<string, int> m; // 일단 먼저 string과 입력 개수를 map에 저장 : 처음부터 pair로 입력받기는 힘들기 때문

    string word;
    while (count--)
    {
        cin >> word;
        if (word.length() < limit)
            continue;

        m[word]++;
    }

    vector<pair<string, int>> vec(m.begin(), m.end()); // map은 value에 의해서 정렬할 수 없기 때문에 pair를 가지는 vector로 복사

    sort(vec.begin(), vec.end(), cmp);

    for (auto &it : vec)
        cout << it.first << '\n';

    return 0;
}