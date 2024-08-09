#include <iostream>

using namespace std;

int gcd(int big, int small)
{
    if (small == 0)
        return big;
    else
        return gcd(small, big % small);
}

// 1. 각 tree 사이의 간격을 구함
// 2. 이전 간격과 현재 간격의 최대 공약수를 구함
// 3. 다음 간격과 이전에 구한 최대 공약수 사이의 최대 공약수를 계속 구함
// 4. 마지막까지 구해진 최대 공약수가 전체 가로수 사이의 균일한 간격이 됨
// 5. 이제 가로수 사이의 간격을 최대 공약수로 정한 간격으로 나눈 후 -1을 해주면 새로 들어가야 하는 가로수의 개수를 알 수 있음

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    int *arr = new int[count];
    int *interval = new int[count - 1]; // 각 tree 사이의 간격은 tree -1개 존재
    int interval_gcd;                   // 간격의 최대 공약수

    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
        if (i == 0) // i가 0이면 interval 계산 불가능 하므로 continue
            continue;

        interval[i - 1] = arr[i] - arr[i - 1];

        if (i == 1) // i가 1이면 gcd를 구할 게 없으니까 gcd를 interval로 두고 끝
            interval_gcd = interval[i - 1];
        else // i가 1보다 크면 이전에 구한 gcd와 현재 interval의 최대 공약수를 구해서 계속 gcd를 누적해서 업데이트
            interval_gcd = gcd(interval[i - 1], interval_gcd);
    }

    int tree_count = 0;
    for (int i = 0; i < count - 1; i++)
        tree_count += interval[i] / interval_gcd - 1;

    cout << tree_count;

    delete[] arr;
}