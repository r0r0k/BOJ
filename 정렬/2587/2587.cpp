#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[5];
    int mean = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        mean += arr[i];
    }

    mean /= 5;

    sort(arr, arr + 5);

    cout << mean << '\n'
         << arr[2];
}