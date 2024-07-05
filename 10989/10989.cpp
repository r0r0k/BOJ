#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    // 메모리 제한이 8MB인데, 1000만개의 int를 받으려면 40MB가 필요하므로 모든 원소를 저장하는 것이 불가능함
    // 따라서 각 원소의 개수만 저장하는 배열 사용
    // 원소의 범위 < 원소의 개수인 경우 count sort 사용 시 메모리 낭비 방지
    // 원소의 범위 > 원소의 개수인 경우 count sort는 오히려 메모리 낭비 심해짐
    int *count_arr = new int[10000]();
    // fill_n(count_arr, 9999, 0); // 0이 아닌 값은 이렇게 초기화 가능

    int tmp;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        count_arr[tmp - 1]++; // 0~9999에 index에 1~10000가 매핑되므로
    }

    for (int i = 0; i < 10000; i++)
        while (count_arr[i]--)
            cout << i + 1 << '\n';
}