#include <iostream>

using namespace std;

// 에라토스테네스의 체 : 알고리즘을 한번만 수행하여 구간에 속하는 모든 소수를 찾을 수 있으므로 200ms 정도 훨씬 더 빠름
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int min, max;
    cin >> min >> max;

    bool *arr = new bool[max + 1]();
    // false로 전부 초기화, 뒤에서 합성수인 index를 true로 설정
    // index와 숫자를 동일시 하기 위해, 어쩔 수 없이 공간 낭비가 되지만 (max - min + 1)이 아닌 (max + 1)에 따라 크기를 지정해줌

    arr[1] = true; // 1은 소수가 아니므로 true로 미리 설정
    for (int i = 2; i <= max; i++)
    {
        if (arr[i] == true) // i가 합성수인 경우 이미 해당 i의 배수는 전부 true로 지워졌기 때문에 뛰어넘어도됨
            continue;
        for (int j = 2 * i; j <= max; j += i) // j == i 일 때는 소수이므로 j == 2 * i 부터 j += i를 하며 합성수를 찾아가야함
            arr[j] = true;
    }

    for (int i = min; i <= max; i++)
        if (arr[i] == false)
            cout << i << '\n';

    delete[] arr;
}