#include <iostream>
#include <vector>

using namespace std;

int N;
bool is_used[14];      // N < 15 : 각 index는 각 column이 현재 사용되었는지 확인
bool pos_diagonal[27]; // 대각선 개수 - 2 * N - 1 : 각 index는 row, column의 합으로 나타내짐
bool neg_diagonal[27]; // 대각선 개수 - 2 * N - 1
// neg_diagonal의 각 index는 row - column으로 나타낼 것인데, row < column 인 경우 index가 음수가 나올 수 있음
// 이러한 경우를 방지하기 위해 row - column의 최솟값이 되는 0 - (N - 1)을 index 0으로 만들기 위해,
// (N - 1)을 더해줌으로써 모든 index를 양수로 겹치지 않게 할 수 있음 : (최댓값은 (N - 1) + (N - 1) = 2 * N - 2 이므로 index에 딱 맞음)

// 아래처럼 하면 대칭인 사용 가능한 대각선도 업데이트되므로 안됨
// bool neg_diagonal[14]; // 음수인 경우 각 index는 row, column의 차를 절댓값하기 때문에, 양쪽 대칭이 되어서 N만큼만 필요

int case_count = 0;

void function(int row)
{
    if (row == N) // N - 1 까지 모든 row가 채워져서 마지막에 row == N인 paramter를 호출하는 경우
    {
        case_count++;
        return;
    }

    // i는 column
    for (int i = 0; i < N; i++)
    {
        if (!is_used[i] && !pos_diagonal[row + i] && !neg_diagonal[row - i + N - 1])
        {
            // if 조건에서 가능한 case가 없으면 function(row + 1)을 호출하지 못하기 때문에, case_count++을 불가능
            is_used[i] = true;
            pos_diagonal[row + i] = true;
            neg_diagonal[row - i + N - 1] = true;

            function(row + 1);

            // 아래에서 function을 하고 나온 후에는 false를 해줘야함
            // 혹시 false가 해당 i에서가 아니라 이전의 i에서 설정된 true를 false로 바꾸면 어쩌나라는 의문이 들 수 있음
            // 이 의문은 if(!is_used[i] && !pos_diagonal[row + i] && !neg_diagonal[row - i + N - 1]) 에서
            // 어쩌피 이전 i에서 true로 설정되지 않은 값에 해당하기 때문에 true가 겹치지 않음을 확인할 수 있음

            is_used[i] = false;
            pos_diagonal[row + i] = false;
            neg_diagonal[row - i + N - 1] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    function(0);

    cout << case_count;

    return 0;
}