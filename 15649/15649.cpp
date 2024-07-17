#include <iostream>
#include <vector>

using namespace std;

int N, M;

int arr[8];      // 현재 저장된 수열을 저장하는 arr : 최대 8개이며, 배열안의 원소 개수를 나타내기 위해 index를 0부터 사용
bool is_used[9]; // arr에 정수가 사용되었으면 true, 아니면 false : 최대 8개인데, index를 1부터 시작하기 위해 크기를 9로 지정

// 왜인지는 모르겠지만, 아래처럼 포인터로 선언해서 동적 할당하면 빌드와 백준에서도 채점은 잘 되는데 editor에서는 빨간줄로 에러가 뜨긴 함
// int *arr; // 현재 저장된 수열을 저장하는 arr
// bool *is_used; // arr에 정수가 사용되었으면 true, 아니면 false

void function(int size)
{
    if (size == M) // 종료 조건 : 수열에 들어있는 원소 개수가 M과 같은 경우 차례대로 출력
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i];

            if (i == M - 1)
                cout << '\n';
            else
                cout << " ";
        }
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (is_used[i] == false)
        {
            arr[size] = i;
            is_used[i] = true;

            function(size + 1);

            // 아래의 코드를 작성해줘야, function(size + 1); 을 호출하고 난 후 돌아와서 마지막에 사용된 원소를 다음 반복문에서 새로 사용할 수 있음
            is_used[i] = false;
            // size로 하려면 바로 아래가 아닌 그 뒤의 코드로 해야함
            // is_used[size] = false;
            // is_used[arr[size]] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    // arr = new int[N];
    // is_used = new bool[N + 1];

    function(0);

    // delete[] arr;
    // delete[] is_used;
    return 0;
}