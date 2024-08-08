#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

#define MOD 1000000007
long n;
unordered_map<long, int> memoization_map;

long fibonacci(long n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (memoization_map[n] != 0)
        return memoization_map[n];

    if (n % 2 == 0)
        return memoization_map[n] = fibonacci(n / 2) * (fibonacci(n / 2) + 2 * fibonacci(n / 2 - 1)) % MOD;
    else
    {
        long tmp1 = fibonacci((n + 1) / 2);
        long tmp2 = fibonacci((n - 1) / 2);

        return memoization_map[n] = ((tmp1 * tmp1) + (tmp2 * tmp2)) % MOD;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cout << fibonacci(n);

    return 0;
}