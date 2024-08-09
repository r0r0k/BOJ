#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 메모리 초과
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    vector<int> vec(200000001, 0);

    int tmp;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        vec[tmp + 100000000]++;
    }

    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        cout << vec[tmp + 100000000] << " ";
    }
}