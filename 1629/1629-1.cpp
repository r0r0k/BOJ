#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int a, b, c;

long recursion(int exponent)
{
    if (exponent == 1)
        return a % c;

    long res = recursion(exponent / 2);
    res = (res * res) % c;
    if (exponent % 2 == 0) // 지수가 짝수인 경우
        return res;
    else // 지수가 홀수인 경우 : a^1 mod c 를 한번 더 곱해주고 다시 mod c 를 해서 return
        // return (res * a) % c; // 이걸 해줘도 int overflow만 안나면 되서 결과 값은 같음
        return (res * (a % c)) % c;
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