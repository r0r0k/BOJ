#include <iostream>
using namespace std;

int dp_0[40]; // dp_0[i] : fibonacci(i)를 호출했을 때, return 0; 이 호출되는 횟수
int dp_1[40]; // dp_1[i] : fibonacci(i)를 호출했을 때, return 1; 이 호출되는 횟수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cnt;
    cin >> cnt;

    while (cnt--)
    {
        int n;
        cin >> n;

        dp_0[0] = 1;
        dp_1[0] = 0;
        dp_0[1] = 0;
        dp_1[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp_0[i] = dp_0[i - 2] + dp_0[i - 1];
            dp_1[i] = dp_1[i - 2] + dp_1[i - 1];
        }

        cout << dp_0[n] << " " << dp_1[n] << '\n';
    }

    return 0;
}