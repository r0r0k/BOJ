#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    vector<bool> vec(20000001, false); // 4464 KB
    // bool arr[200000001] = {
    //     0,
    // };
    // 197212 KB, int로 하면 메모리 초과

    int tmp;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        vec[tmp + 10000000] = true;
        // arr[tmp + 100000000] = true;
    }

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        cout << vec[tmp + 10000000] << " ";
        // cout << arr[tmp + 100000000] << " ";
    }
}