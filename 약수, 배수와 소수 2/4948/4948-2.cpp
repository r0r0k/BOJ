
#include <iostream>

using namespace std;

void find_prime(bool *arr, int max)
{
    // 정적 배열일 때는 이렇게 해도 되지만, 동적 할당을 한 포인터인 경우 이렇게 하면 sizeof(arr)가 포인터의 크기를 리턴하므로 불가능
    // int max = sizeof(arr) / sizeof(arr[0]) - 1;

    arr[1] = true;
    for (int i = 2; i <= max; i++)
    {
        if (arr[i] == true)
            continue;
        for (int j = 2 * i; j <= max; j += i)
            arr[j] = true;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int min;
    cin >> min;

    int max;
    int count;
    bool *arr;

    while (min != 0)
    {
        count = 0;
        max = 2 * min;
        arr = new bool[max + 1]();

        find_prime(arr, max);

        for (int i = min + 1; i <= max; i++)
            if (arr[i] == false)
                count++;

        cout << count << '\n';

        delete[] arr;
        cin >> min;
    }
}