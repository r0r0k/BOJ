#include <iostream>
#include <vector>

using namespace std;

long int factorial(int number)
{
    if (number == 0)
        return 1;
    else
        return number * factorial(number - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << factorial(n);

    return 0;
}