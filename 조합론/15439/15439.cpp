#include <iostream>

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int number;
    cin >> number;

    int r = 2;

    int npr = 1;

    // 1. loop
    for (int i = 0; i < r; i++)
        npr *= (number - i);

    // 2. factorial : number 범위가 2017까지라 overflow남
    // npr = 1;
    // if (number != 1)
    //     npr = factorial(number) / factorial(number - r);
    cout << npr;
}