#include <iostream>

using namespace std;

int factorial(int number)
{
    if (number == 0) // 0! = 1이기 때문
        return 1;
    else
        return number * factorial(number - 1);

    // int ret = 1;

    // if (number != 0)
    //     for (int i = 0; i < number; i++)
    //         ret *= (number - i);

    // return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int number;
    cin >> number;

    int factorial_ = 1;

    // loop
    for (int i = 0; i < number; i++)
        factorial_ *= (number - i);

    // recursion
    factorial_ = factorial(number);
    cout << factorial_;
}