#include <iostream>
using namespace std;

int N, K; // N,K <= 4,000,000
int divisor = 1000000007;

int factorial(int n) // O(n)은 시간 제한이 1초인 경우, n<= 10,000,000 일 때 성립
{
    if (n == 0)
        return 1;

    long res = 1; // res 자체는 결과적으로 int가 되겠지만, 아래에서 (res * i) 에서 int overflow가 날 수 있어서 res를 미리 long으로 선언
    for (int i = 2; i <= n; i++)
        res = (res * i) % divisor;

    return res;
}

// parameter가 (n-k)!*k! 인 경우, divisor로 나누어 주지 않으면 int overflow가 나서 long으로 받아줌
// divisor로 나눠주고 받으면 int로 받아도 됨
long recursion(long n, int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return n % divisor;

    long res = recursion(n, exponent / 2);
    res = (res * res) % divisor;

    if (exponent % 2 == 0)
        return res;
    else
        return (res * (n % divisor)) % divisor;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    int numerator = factorial(N);
    long denominator = factorial(N - K) * long(factorial(K)); // 계산 값이 int overflow가 날 수 있어서 한쪽을 conversion

    cout << (numerator * recursion(denominator, divisor - 2)) % divisor;

    return 0;
}