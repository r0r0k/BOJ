#include <iostream>
#include <cmath>

using namespace std;

void cantor_set(int length)
{
    if (length == 0)
    {
        cout << "-";
        return; // 아래 코드는 실행할 필요 X
    }

    cantor_set(length - 1);

    for (int i = 0; i < static_cast<int>(pow(3, length - 1)); i++)
        cout << " ";

    cantor_set(length - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int length;
    while (cin >> length) // EOF를 만나면 cin은 false를 return
    {
        cantor_set(length);
        cout << '\n';
    }

    return 0;
}