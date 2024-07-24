#include <iostream>
#include <climits>
using namespace std;

int cnt;             // 사람들이 몇명있는지 저장할 변수 : cnt <= 20
int s_min = INT_MAX; // 팀간의 능력치 차이의 최솟값을 저장할 변수
int **matrix;        // 각 사람들의 능력치를 저장할 매트릭스 : index를 1부터 사용하기 위해 [cnt + 1][cnt + 1] 크기를 가지도록 main에서 할당
int s1_arr[10];      // 한 팀을 구성하는 사람들의 번호를 저장할 배열 : 한 팀만 정하면 나머지는 is_used로 파악 가능함
int s2_arr[10];      // 다른 팀을 구성하는 사람들의 번호를 저장할 배열 : is_used를 통해 마지막에 계산
bool is_used[21];    // 각 사람들이 사용되었는지 index로 저장 : index를 1부터 사용하기 위해 (cnt + 1)의 크기를 가지도록 선언

int cal(int *arr)
{
    int result = 0;
    for (int i = 0; i < cnt / 2; i++)
        for (int j = 0; j < cnt / 2; j++)
            result += matrix[arr[i]][arr[j]];

    return result;
}

void DFS(int cur)
{
    if (cur == cnt / 2) // 종료 조건
    {
        int s1 = cal(s1_arr);

        // s2를 계산하기 위해 is_used의 false인 index를 찾아서 대입
        int j = 0;
        for (int i = 1; i <= cnt; i++)
        {
            if (!is_used[i])
            {
                s2_arr[j] = i;
                j++;
            }
        }
        int s2 = cal(s2_arr);

        if (s_min > abs(s1 - s2))
            s_min = abs(s1 - s2);
        return;
    }

    int i;
    for ((cur == 0) ? (i = 1) : (i = s1_arr[cur - 1] + 1); i <= cnt; i++) // 사람들 번호의 순서가 상관 없기 때문에 오름차순으로 하는게 빠름
    {
        if (!is_used[i])
        {
            s1_arr[cur] = i;
            is_used[i] = true;

            DFS(cur + 1);
            is_used[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> cnt;

    // 이차원 배열 동적 할당
    matrix = new int *[cnt + 1];
    for (int i = 1; i <= cnt; i++)
        matrix[i] = new int[cnt + 1];

    // 입력
    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j <= cnt; j++)
            cin >> matrix[i][j];

    DFS(0);
    cout << s_min;

    // 이차원 배열 동적 할당 해제
    for (int i = 1; i <= cnt; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}