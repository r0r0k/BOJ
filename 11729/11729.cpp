#include <iostream>
#include <vector>

using namespace std;

void hanoi(int n, int start, int mid, int end) // mid가 필요한 이유는, 해당 위치를 기억해놨다가 start, end로 recursion에서 써야 하기 때문
{
    if (n == 1) // 옮길 탑이 1개인 경우 바로 start -> end로 옮기면 되기 때문 (최소 단위)
    {
        cout << start << " " << end << '\n';
        return;
    }

    hanoi(n - 1, start, end, mid);       // 1. 위부터 (n - 1)개를 start -> mid 로 옮기고 : a(n-1)
    cout << start << " " << end << '\n'; // 2. 맨 아래 1개를 start -> end로 옮기고  : 1
    hanoi(n - 1, mid, start, end);       // 3. 다시 1.에서 옮긴 (n - 1)개를 mid -> end로 옮김 : a(n-1)

    // 총 이동 횟수는 a(n) = 2*a(n-1) + 1이므로 등비수열의 합 공식에 의해 2^n - 1
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; // 탑 개수
    cin >> n;

    cout << (1 << n) - 1 << '\n'; // 2^count - 1을 left shift로 구하는 방법
    hanoi(n, 1, 2, 3);

    return 0;
}