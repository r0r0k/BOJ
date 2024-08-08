#include <iostream>
using namespace std;

int N, M, K;

int m1[100][100];
int m2[100][100];
int res[100][100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> m1[i][j];

    cin >> M >> K;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            cin >> m2[i][j];

    for (int n = 0; n < N; n++)
    {
        for (int k = 0; k < K; k++)
        {
            for (int m = 0; m < M; m++)
            {
                res[n][k] += m1[n][m] * m2[m][k]; // (N, K) = (N, M) * (M, K)
            }
            cout << res[n][k] << " ";
        }
        cout << '\n';
    }

    return 0;
}