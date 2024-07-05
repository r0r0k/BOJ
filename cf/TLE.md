```
// 2751번

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // 기본적으로 C와 C++은 동일한 buffer를 사용하여 stdio, iostream 버퍼를 모두 사용 : thread 안전
    // 아래 코드를 사용하면 C <-> C++ 간의 표준 stream 동기화 해제
    // 따라서, C++ iostream 버퍼만 입출력을 하므로 stdio의 printf, scanf 사용 불가능 : multi thread에서는 안전 X
    // 600ms -> 276 ms
    ios::sync_with_stdio(false);

    // 입력마다 출력 buffer를 비우지 않게 하여 cin, cout의 입출력을 풀어줌
    // 대신 입출력 순서 보장 X
    // 600ms -> 276ms -> 272ms 까지 단축
    cin.tie(NULL);
    cout.tie(NULL);

    int count;

    cin >> count;

    int *arr = new int[count];

    for (int i = 0; i < count; i++)
        cin >> arr[i];

    sort(arr, arr + count);
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << '\n';
        // 여기서 '\n' 대신 endl을 쓰면 cout 부하때문에 시간 초과 발생
        // endl을 개행문자 출력 뿐만 아니라 출력 buffer를 flush하는 역할도 하기 때문에 시간 많이 사용
        // endl을 쓰면 위에서 사용한 cin.tie, cout.tie 효과도 없음
    }

    delete[] arr;
}
```            