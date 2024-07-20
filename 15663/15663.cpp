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

    int cmp = 0; // 현재 size에서 저장한 arr에 저장한 number와 동일한지 체크하기 위한 변수 : 반복문 밖에서 초기화해줘야함
    for (int i = 0; i < N; i++)
    {
        if (!is_used[i] && cmp != number[i]) // 다음 `size`에서는 그 재귀 함수 내에서 cmp가 존재하므로, 상관 X
        {
            cmp = number[i];
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