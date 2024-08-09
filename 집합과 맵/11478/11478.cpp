#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    set<string> s;

    int str_length = str.length();
    int index; // substr 함수를 통해 몇 번째 string을 읽을지
    int size;  // substr 함수를 통해 어떤 길이만큼 string을 읽을지

    // 1. size에 따라 size == 1부터 size == str_length로 고정해두고, index 증가시키며 substring을 set에 추가 : 816 ms
    // 항상 두 변수가 독립적으로 하나가 고정되고, 하나는 증가할 때 for이나 반복문을 중첩해서 써줘야 하는거 잘 생각하기
    for (size = 1; size <= str_length; size++)
    {
        for (index = 0; index + size <= str_length; index++)
            s.insert(str.substr(index, size));

        // th = 0;
        // while (th + size <= str_length)
        // {
        //     s.insert(str.substr(th, size));
        //     th++;
        // }
    }

    // 2. index의 시작점을 바꿔가며 tmp을 str의 str_length - 1(마지막 index)까지 계속 쌓아서 set에 추가 : 472 ms
    string tmp = "";
    for (int i = 0; i < str_length; i++)
    {
        for (int j = index; j < str_length; j++)
        {
            tmp += str[j];
            s.insert(tmp);
        }
        tmp = ""; // 한 index가 끝났으면 tmp 초기화
    }

    cout << s.size();
}