#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int number)
{
    for (int i = 2; i <= sqrt(number); i++)
        if (number % i == 0)
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int min, max;
    cin >> min >> max;

    for (int i = min; i <= max; i++)
    {
        if (i == 1)
            continue;
        if (i == 2)
            cout << "2\n";

        else if (is_prime(i))
            cout << i << '\n';
    }
}