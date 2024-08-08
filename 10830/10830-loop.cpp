#include <iostream>
using namespace std;

int n;
long ex;
int matrix[5][5]; // 기존 행렬
int mid[5][5];    // 중간 계산값을 저장할 행렬
int res[5][5];    // 결과값을 저장해서 계속 mid에 업데이트하고 마지막에 출력할 행렬

// ex의 최댓값이 1천억이기 때문에 반복문으로 하면 무조건 시간초과가 발생함
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> ex;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            mid[i][j] = matrix[i][j];
        }

    ex--; // 행렬의 n제곱은 n - 1번만 수행하면 되기 때문
    while (ex--)
    {
        for (int i = 0; i < n; i++)                                 // n
            for (int j = 0; j < n; j++)                             // k
                for (int k = 0; k < n; k++)                         // m
                    res[i][j] += (mid[i][k] * matrix[k][j]) % 1000; // mid와 원래 행렬을 곱해서 res에 업데이트

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                mid[i][j] = res[i][j] % 1000; // 다음 반복문을 위해 mid에 res를 마지막에 업데이트
                if (ex > 0)
                    res[i][j] = 0; // 다음 반복문을 위해 res가 마지막이 아니라면 0으로 초기화
            }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << res[i][j] % 1000 << " ";
        cout << '\n';
    }

    return 0;
}