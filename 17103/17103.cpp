#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    // 미리 입력값 범위의 에라토스 테네스 체를 선언 후 아래에서 계속 사용하도록 함
    bool *arr = new bool[1000001]();
    int max = 1000000;

    arr[1] = true;
    for (int i = 2; i <= max; i++)
    {
        if (arr[i] == true)
            continue;
        for (int j = 2 * i; j <= max; j += i)
            arr[j] = true;
    }

    int number;
    int partition_count;
    int cmp; // 소수의 합을 계산하기 위한 변수 : 반복문에서 number 자체를 건드리면 안되기 때문

    while (count--)
    {
        partition_count = 0;
        cin >> number;

        for (int i = 2; i <= number / 2; i++) // 소수의 합은 대칭이므로 (number / 2) 까지만 검사해도 됨
        {
            cmp = number;       // cmp에 number 대입해주는 위치 중요 : 바깥 반복문에서 해주면 cmp가 누적되서 변하므로 안됨
            if (arr[i] == true) // 1. 소수가 아닌 경우 continue
                continue;

            cmp -= i;              // 2. 소수인 경우 cmp에서 해당 소수를 빼줌
            if (arr[cmp] == false) // 3. 빼준 cmp가 소수인지 확인하고 소수라면 partition_count++
                partition_count++;
        }

        cout << partition_count << '\n';
    }

    delete[] arr;
}