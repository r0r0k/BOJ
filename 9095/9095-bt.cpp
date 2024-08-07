#include <iostream>
using namespace std;

int cnt = 0;
int n;

void backtracking(int cur)
{
    if (cur == n)
    {
        cnt++;
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        if (cur + i <= n)
            backtracking(cur + i);
        else // 크면 반복문 더 할 필요 없음
            break;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size;
    cin >> size;
    while (size--)
    {
        cin >> n;
        backtracking(0);
        cout << cnt << '\n';
        cnt = 0;
    }

    return 0;
}