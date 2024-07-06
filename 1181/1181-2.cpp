#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b)
{
    if (a.length() < b.length())
        return true;
    else if (a.length() == b.length()) // string 길이가 같은 우우
        return a < b;                  // 아스키 코드 상에서 사전 순으로 뒤에 있으면 string 값 자체가 더 커짐
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    vector<string> vec;

    string tmp;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end(), compare);
    // 중복 처리를 위한 코드
    // 1. unique는 전체 vec를 한번에 탐색하는 것이 아닌 연속된 요소의 중복을 처리하므로 sort를 먼저 해줘야함
    // 2. unique는 중복 값의 첫번째 요소를 가리키므로 erase의 첫번째 인자에 unique를 두고 마지막 인자에 end를 두면 됨
    // 추가로 begin은 시작 요소를 가리키지만, end는 마지막 요소가 아닌 마지막 요소의 뒤를 가리킴
    // 그래서 erase, unique 모두 범위가 [,)가 됨
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << '\n';
}