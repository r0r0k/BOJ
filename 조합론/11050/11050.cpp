#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int number;
    cin >> number;

    int r;
    cin >> r;

    int ncr = factorial(number) / (factorial(r) * factorial(number - r));

    // ncr = 1;
    // for (int i = 0; i < number; i++)
    // {
    //     ncr *= (number - i);
    // }

    // for (int i = 0; i < r; i++)
    // {
    //     ncr /= r - i;
    // }

    // for (int i = 0; i < number - r; i++)
    // {
    //     ncr /= number - r - i;
    // }

    cout << ncr;
}