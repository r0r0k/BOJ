#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int number[8];   // 입력으로 받은 숫자를 저장하는 배열
int arr[8];      // 출력할 수열을 저장할 배열
bool is_used[8]; // number의 index가 사용되었는지 저장하는 배열

void foo(int size)
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
    }

    for (int i = 0; i < N; i++)
    {
        if (!is_used[i])
        {
            arr[size] = number[i];
            is_used[i] = true;

            foo(size + 1);
            is_used[i] = false;
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

    foo(0);

    return 0;
}