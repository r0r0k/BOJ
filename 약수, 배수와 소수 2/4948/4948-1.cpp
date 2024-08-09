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

    int min;
    cin >> min;

    int count;
    while (min != 0)
    {
        count = 0;
        for (int i = min + 1; i <= 2 * min; i++)
        {
            if (i == 2) // i는 2부터 들어오기 때문에 1일 때는 고려해주지 않아도 됨
                count++;
            else if (is_prime(i))
                count++;
        }
        cout << count << '\n';
        cin >> min;
    }
}