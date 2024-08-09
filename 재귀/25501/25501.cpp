
#include <iostream>

using namespace std;

int call_count = 0; // recursion하며 update하기 위해, 전역 변수로 설정

int recursion(const string &s, int l, int r) // parameter를 넘길 떄, string s로만 넘기면 복사본이 넘어가서, recursion에 시간 많이 들어서 TLE 발생
{
    call_count++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

int isPalindrome(const string &s) // parameter를 넘길 떄, string s로만 넘기면 복사본이 넘어가서, recursion에 시간 많이 들어서 TLE 발생
{
    return recursion(s, 0, s.length() - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    string tmp;
    while (count--)
    {
        call_count = 0;
        cin >> tmp;
        cout << isPalindrome(tmp) << " " << call_count;
        if (count > 0)
            cout << '\n';
    }

    return 0;
}