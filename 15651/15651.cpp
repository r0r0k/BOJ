#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[7]; // N <= 7

void function(int size)
{
    if (size == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i];

            if (i == M - 1)
                cout << '\n';
            else
                cout << ' ';
        }
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        arr[size] = i;
        function(size + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    function(0);

    return 0;
}