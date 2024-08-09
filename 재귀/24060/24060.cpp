#include <iostream>
#include <vector>

using namespace std;

int push_count = 0;     // 현재 push가 몇번 됬는지
int required_count = 0; // 요구하는 push 횟수 : 전역 변수명을 count로 std::count와 모호해서 에러 발생
int value = 0;          // 요구하는 값

void merge(int *, int, int, int); // 함수 선언 안해주면, 아래에서 merge_sort를 쓸 때, merge를 찾지 못함

void merge_sort(int *arr, int l, int r)
{
    if (l < r) // 원소가 1개가 남을 때 까지 recursion
    {
        int m = l + (r - l) / 2; // (l + r) / 2 의 overflow를 방지하기 위해 이렇게 쓰기도 함
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int *arr, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    // int t = 0;

    vector<int> tmp; // 크기는 (r - l + 1) 이므로 int *tmp = new int[r - l + 1]로 선언해도 됨

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
            tmp.push_back(arr[i++]);
        else
            tmp.push_back(arr[j++]);
    }

    while (i <= m)
        tmp.push_back(arr[i++]);
    while (j <= r)
        tmp.push_back(arr[j++]);

    int t = 0;
    while (l <= r)
    {
        arr[l++] = tmp[t++];

        push_count++;
        if (push_count == required_count)
            value = tmp[--t];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size;
    cin >> size >> required_count;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
        cin >> arr[i];

    merge_sort(arr, 0, size - 1);

    if (push_count < required_count)
        cout << "-1";
    else
        cout << value;

    delete[] arr;

    return 0;
}