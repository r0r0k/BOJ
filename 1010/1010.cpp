#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n <= 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    int west;
    int east;

    int result;
    while (count--)
    {
        cin >> west >> east;

        // cout << factorial(east) / (factorial(west) * factorial(east - west)) << "\n";
        // 위 코드는 long long이어도 29!에서 overflow 발생하므로 계산 불가

        result = 1;
        int r = 1; // 나누어 떨어지게 하기 위해 1부터 역으로 분모의 factorial 계산
        for (int i = 0; i < west; i++)
        {
            result *= (east - i); // 분자는 그대로 계산
            result /= r;
            r++;
        }

        cout << result << '\n';
    }
}