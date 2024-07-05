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

    int min;
    int min_index;
    int tmp;

    // selection sort
    for (int i = 0; i < size - 1; i++)
    {
        min = arr[i];
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }

    for (int i = 0; i < size; i++)
        cout << arr[i] << '\n';
    delete[] arr;
}