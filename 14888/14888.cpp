#include <iostream>
#include <vector>
using namespace std;

int res_min = 1000000000;  // 계산값의 최솟값을 저장하는 변수
int res_max = -1000000000; // 계산값의 최댓값을 저장하는 변수
int cnt;                   // 입력 받은 정수의 개수
int arr[11];               // 입력 받은 정수를 저장하는 배열 : 최대 11개 입력
int op[4];                 // operator의 개수를 저장하는 배열 : index 순서대로, + - * /
int op_arr[10];            // operator의 순서(어떤 operator인지)를 저장하는 배열 : value 값이 0,1,2,3 이면, 순서대로 + - * /

void DFS(int cur)
{
    if (cur == cnt - 1) // operator의 개수가 cnt - 1 개만큼 채워졌으면, 종료 조건
    {
        int result = arr[0];              // result 값을 계산하기 위해 먼저 첫번째 정수 입력
        for (int i = 0; i < cnt - 1; i++) // op_arr와 arr를 순회하며, result를 계산
        {
            switch (op_arr[i]) // op_arr 값에 따라 연산 수행 : arr의 index는 (i+1)이어야함
            {
            case 0:
                result += arr[i + 1];
                break;
            case 1:
                result -= arr[i + 1];
                break;
            case 2:
                result *= arr[i + 1];
                break;
            case 3:
                result /= arr[i + 1];
                break;
            }
        }

        if (res_min > result) // 최솟값 업데이트
            res_min = result;
        if (res_max < result) // 최댓값 업데이트
            res_max = result;

        return;
    }

    for (int i = 0; i < 4; i++) // op 배열을 순회하며, operator가 존재하는 경우를 탐색
    {
        if (op[i] > 0) // operator가 존재하는 경우 : value가 0보다 큰 경우
        {
            op[i]--;         // operator를 사용하였기 때문에 1 감소시켜줌
            op_arr[cur] = i; // 현재 cur의 index에 operator를 저장해줌

            DFS(cur + 1); // cur + 1를 재귀적으로 호출
            op[i]++;      // 재귀 호출 후 돌아오면, 사용한 operator를 반납해야 하기 때문에 1을 증가시켜줌
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> cnt;

    int tmp;
    for (int i = 0; i < cnt; i++)
        cin >> arr[i];

    for (int i = 0; i < 4; i++)
        cin >> op[i];

    DFS(0);

    cout << res_max << '\n'
         << res_min;

    return 0;
}