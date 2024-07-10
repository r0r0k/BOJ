#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    // false : 열림, true : 닫힘
    // 미리 초기화해주면서 1번째 사람은 모든 창문을 열도록 설정
    bool *arr = new bool[count + 1]();

    for (int i = 2; i <= count; i++)
        for (int j = 2 * i; j <= count; j += i)
            arr[j] = !arr[j];

    int count = 0;
    for (int i = 1; i <= count + 1; i++)
        if (arr[i] == false)
            count++;

    cout << count;
}
