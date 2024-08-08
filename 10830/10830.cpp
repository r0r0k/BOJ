#include <iostream>
using namespace std;

int n;
long ex;
int matrix[5][5]; // 기존 행렬
int mid[5][5];    // 결과 값을 보존하기 위해 계산에 사용할 행렬
int res[5][5];    // 결과 값을 저장할 배열 : 매 재귀 호출에서 결과값을 담는데만 사용하고 결국 mid에 결과값을 다시 넘겨줌

void recursion(long exponent)
{
    if (exponent == 1)
        return;

    recursion(exponent / 2); // O(logn)의 재귀 호출한 결과값으로 업데이트된 mid로 아래의 행렬 계산

    // (N, K) = (N, M) x (M, K)
    for (int i = 0; i < n; i++) // N
    {
        for (int j = 0; j < n; j++) // K
        {
            res[i][j] = 0;
            for (int k = 0; k < n; k++) // M
            {
                res[i][j] += (mid[i][k] * mid[k][j]) % 1000;
            }
        }
    }

    // 여기서 mid를 업데이트해야 반복문 내에서 간섭이 안됨
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mid[i][j] = res[i][j] % 1000;

    if (exponent % 2 != 0) // matrix를 한번 더 곱해줘야함
    {
        for (int i = 0; i < n; i++) // N
        {
            for (int j = 0; j < n; j++) // K
            {
                res[i][j] = 0;
                for (int k = 0; k < n; k++) // M
                {
                    res[i][j] += (mid[i][k] * matrix[k][j]) % 1000;
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mid[i][j] = res[i][j] % 1000;
    }
}

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
            res[i][j] = matrix[i][j]; // ex == 1인 경우 바로 출력하기 위해 미리 넣어줌
        }

    recursion(ex);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << res[i][j] % 1000 << " "; // ex가 1인 경우 때문에 1000으로 나눠줘야함
        cout << '\n';
    }

    return 0;
}