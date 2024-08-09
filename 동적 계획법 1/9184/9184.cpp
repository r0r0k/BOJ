#include <iostream>
#include <map>

using namespace std;

int n;
map<tuple<int, int, int>, int> w;
// 이렇게 선언해서 써도 됨
// int w[21][21][21];

int DP(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return DP(20, 20, 20);

    tuple<int, int, int> tmp = {a, b, c};
    if (w[tmp] != 0) // 존재하지 않으면 map은 0을 리턴
        return w[tmp];

    // if (w.find(tmp) != w.end()) // 이렇게도 가능
    //     return w[tmp];

    if (a < b && b < c)
        return w[tmp] = DP(a, b, c - 1) + DP(a, b - 1, c - 1) - DP(a, b - 1, c);
    else
        return w[tmp] = DP(a - 1, b, c) + DP(a - 1, b - 1, c) + DP(a - 1, b, c - 1) - DP(a - 1, b - 1, c - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    while (1)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << DP(a, b, c) << '\n';
    }

    return 0;
}