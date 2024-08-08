#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

int a, b, c;
unordered_map<int, int> memoization;

long recursion(int exponent)
{
    if (exponent == 1)
        return a % c;

    if (memoization[exponent] != 0)
        return memoization[exponent];

    // dp를 쓰면 최대 범위가 2147483647이므로 메모리 초과남
    // if (dp[exponent] != -1) // 나머지 연산이므로 0이 될 수 있기 때문
    //     return dp[exponent];

    if (exponent % 2 == 0) // 지수가 짝수인 경우
        return memoization[exponent] = (recursion(exponent / 2) * recursion(exponent / 2)) % c;
    else // 지수가 홀수인 경우
        return memoization[exponent] = (recursion(exponent / 2 + 1) * recursion(exponent / 2)) % c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;

    cout << recursion(b);

    return 0;
}