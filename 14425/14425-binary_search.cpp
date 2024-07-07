#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int set_size, string_count;
    cin >> set_size >> string_count;

    vector<string> vec(set_size);
    for (int i = 0; i < set_size; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end()); // binary_search를 하기 위해선 string도 정렬 필요

    int count = 0;
    string tmp;
    for (int i = 0; i < string_count; i++)
    {
        cin >> tmp;
        if (binary_search(vec.begin(), vec.end(), tmp))
            count++;
    }

    cout << count;
}