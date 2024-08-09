#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int number)
{
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;
    else
        return fibonacci(number - 1) + fibonacci(number - 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int number;
    cin >> number;

    cout << fibonacci(number);
    return 0;
}