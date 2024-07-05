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

    // insertion sort 1.
    for (int i = 1; i < size; i++)
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
            // if(arr[j] >= arr[j-1])
            //     break;
            swap(&arr[j], &arr[j - 1]);

    // insertion sort 2.
    int key;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        for (int j = i - 1; j >= 0 && key < arr[j]; j--)
            swap(&arr[j + 1], &arr[j]);
    }

    for (int i = 0; i < size; i++)
        cout << arr[i] << '\n';
    delete[] arr;
}