#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string number;
    cin >> number;

    sort(number.begin(), number.end(), greater<char>());

    cout << number;
}