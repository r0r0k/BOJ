#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    // 1.
    int square_number_cnt = 0;
    for (int i = 1; i * i <= count; i++)
        square_number_cnt++;

    // 2.
    square_number_cnt = sqrt(count);

    cout << square_number_cnt;
}