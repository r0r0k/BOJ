#include <iostream>
#include <algorithm>

using namespace std;

int compare(int a, int b)
{
    return a > b;
}

int main()
{
    int count;
    int range;

    cin >> count >> range;

    int *arr = new int[count];

    for (int i = 0; i < count; i++)
        cin >> arr[i];

    sort(arr, arr + count, compare);

    cout << arr[range - 1];

    delete[] arr;
}