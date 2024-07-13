#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    int min = 1000001; // 들어오는 약수의 최솟값을 저장할 변수
    int max = 0;       // 들어오는 약수의 최댓값을 저장할 변수
    int tmp;           // 들어오는 약수를 저장할 변수
    while (count--)
    {
        cin >> tmp;
        if (tmp < min)
            min = tmp;
        if (tmp > max)
            max = tmp;
    }

    cout << min * max; // 약수의 최솟값과 최댓값을 곱하면 원하는 수가 나옴
}