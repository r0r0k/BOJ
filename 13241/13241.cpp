#include <iostream>

using namespace std;

long int gcd(long int big, long int small)
{
    if (small == 0)
        return big;
    else
        return gcd(small, big % small);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long int n1, n2;

    cin >> n1 >> n2;

    cout << n1 * n2 / (n1 > n2 ? gcd(n1, n2) : gcd(n2, n1));
}