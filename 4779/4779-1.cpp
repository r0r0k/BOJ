#include <iostream>
#include <cmath>

using namespace std;

void cantor_set(string &str, int l, int r)
{
    if (l < r) // l, r의 index가 같아질 때 까지 반복
    {
        int i = l + (r - l + 1) / 3;     // index : [l,r] 의 3등분 중 중간의 시작 index
        int j = i + (r - l + 1) / 3 - 1; // index : [l,r] 의 3등분 중 중간의 끝 index

        int k = i;
        while (k <= j)      // i부터 j까지 공백 대입
            str[k++] = ' '; // " "는 string이므로 char(index 요소)에 대입 불가능

        cantor_set(str, l, i - 1); // 3등분 중 첫번째에 대해 재귀
        cantor_set(str, j + 1, r); // 3등분 중 마지막에 대해 재귀
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    int length;
    while (cin >> length) // EOF를 만나면 cin은 false를 return
    {
        str = "";
        length = static_cast<int>(pow(3, length)); // double을 int에 return하므로 형변환 해줬음
        while (length--)
            str += '-';

        cantor_set(str, 0, str.length() - 1);
        cout << str << '\n';
    }

    return 0;
}