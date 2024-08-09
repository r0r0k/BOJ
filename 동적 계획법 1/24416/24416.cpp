#include <iostream>
using namespace std;

int code1_cnt = 0;
int code2_cnt = 0;
int f[41];

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        code1_cnt++;
        return 1; // code 1
    }
    else
        return fib(n - 1) + fib(n - 2);
}

void fibonacci(int n)
{
    f[1] = f[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        code2_cnt++;
        f[i] = f[i - 1] + f[i - 2]; // code2
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    fib(n);
    fibonacci(n);

    cout << code1_cnt << " " << code2_cnt;

    return 0;
}