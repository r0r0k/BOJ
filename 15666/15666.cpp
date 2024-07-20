#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int number[8];
int arr[8];

void func(int size, int prev_index) // 비내림차순을 위해 prev_index 추가
{
    if (size == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i];

            if (i == M - 1)
                cout << "\n";
            else
                cout << " ";
        }
        return;
    }

    int cmp = 0;
    for (int i = prev_index; i < N; i++)
    {
        if (cmp != number[i])
        {
            cmp = number[i];
            arr[size] = number[i];

            func(size + 1, i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> number[i];

    sort(number, number + N);

    func(0, 0);

    return 0;
}