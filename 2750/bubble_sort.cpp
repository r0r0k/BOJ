#include <iostream>
#include <algorithm>

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
        cin >> arr[i];

    // bubble sort
    for (int i = size; i > 0; i--)
        for (int j = 0; j < i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

    for (int i = 0; i < size; i++)
        cout << arr[i] << '\n';
    delete[] arr;
}
