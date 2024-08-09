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
    int size = 0; // 배열 크기를 저장하는 변수 (중복을 제거하면 count와 달라질 수 있으므로)

    string tmp;            // 중복을 비교하기 위한 변수
    bool same_string_flag; // 중복 string이 존재하는지 확인

    // 중복된 string을 제거
    for (int i = 0; i < count; i++)
    {
        same_string_flag = false;
        cin >> tmp;
        for (int j = 0; j < size; j++) // 기존 배열을 탐색하며 중복이 있는지 체크
        {
            if (tmp == arr[j])
            {
                same_string_flag = true;
                break;
            }
        }
        if (!same_string_flag) // 중복이 없는 경우
        {
            arr[size] = tmp;
            size++;
        }
    }

    sort(arr, arr + size, compare);

    for (int i = 0; i < size; i++)
        cout << arr[i] << '\n';
}