#include <iostream>
using namespace std;

long n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    long left = 1;
    long right = n * n;
    long mid;

    while (left <= right)
    {
        long cnt = 0;
        mid = (left + right) / 2;

        bool flag = false;
        for (int row = 1; row <= n; row++)
        {
            for (int col = 1; col <= n; col++)
            {
                if ((row * col) / mid == 0 || row * col == mid)
                    cnt++;

                if (cnt >= k)
                {
                    right = mid - 1;
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }

        if (!flag) // cnt < k
            left = mid + 1;
    }

    cout << mid;
    return 0;
}