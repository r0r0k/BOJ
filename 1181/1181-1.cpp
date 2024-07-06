#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    if (a.length() < b.length())
        return true;
    else if (a.length() == b.length()) // string 길이가 같은 우우
        return a < b;                  // 아스키 코드 상에서 사전 순으로 뒤에 있으면 string 값 자체가 더 커짐
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    string *arr = new string[count];

    for (int i = 0; i < count; i++)
        cin >> arr[i];

    sort(arr, arr + count, compare);

    // 여기서 중복을 처리, i < count 까지 하면 마지막에 i+1이 배열의 범위를 넘어서므로 마지막에 원소를 추가로 출력
    // 어쩌피 마지막 원소와 중복은 이전에 출력되지 않으므로 마지막을 무조건 출력해주는게 맞음
    for (int i = 0; i < count - 1; i++)
        if (arr[i] != arr[i + 1])
            cout << arr[i] << '\n';
    cout << arr[count - 1];
}