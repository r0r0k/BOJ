#include <iostream>

using namespace std;

// 메모리 초과 : count가 2,100,000,000이므로 arr[count + 1]의 최댓값이 64MB를 넘게 됨
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    // false : 열림, true : 닫힘
    // 미리 초기화해주면서 1번째 사람은 모든 창문을 열도록 설정
    bool *arr = new bool[count + 1]();

    for (int i = 2; i <= count; i++)
        for (int j = i; j <= count; j += i) // 에라토스테네스의 체와 알고리즘은 비슷하지만, 소수를 찾는 것이 아니므로 2 * i 부터가 아닌 i 부터 시작
            arr[j] = !arr[j];

    int open_cnt = 0;
    for (int i = 1; i <= count; i++)
        if (arr[i] == false)
            open_cnt++;

    cout << open_cnt;

    delete[] arr;
}
