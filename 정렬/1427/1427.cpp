#include <iostream>
#include <algorithm>

using namespace std;

int compare(int a, int b)
{
    return a > b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int number;
    cin >> number;

    int arr[10]; // number의 범위가 1,000,000,000 까지 이므로 자릿수 10개 필요

    int i = 0;
    while (number != 0)
    {
        arr[i] = number % 10;
        number /= 10;
        i++;
    }

    sort(arr, arr + i, compare);

    for (int j = 0; j < i; j++)
        cout << arr[j];
}