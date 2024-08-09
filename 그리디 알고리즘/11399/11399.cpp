#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector<int> times;
    int time;
    for (int i = 0; i < n; i++)
    {
        cin >> time;
        times.push_back(time);
    }

    sort(times.begin(), times.end());

    int res = 0;
    int i = 0;
    for (auto it : times)
    {
        res += it * (n - i);
        i++;
    }

    // for (int i = 0; i < n; i++)
    //     res += times[i] * (n - i);

    cout << res;

    return 0;
}