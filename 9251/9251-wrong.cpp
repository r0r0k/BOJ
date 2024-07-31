#include <iostream>
using namespace std;

// 반례 : VREGDFELK - VLSKD
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int count = 0;
    int i = 0;
    int j = 0;

    while (i < s1.length() && j < s2.length())
    {
        cout << s1[i] << " " << s2[j] << '\n';
        if (s1[i] > s2[j])
            i++;
        else if (s1[i] < s2[j])
            j++;

        else
        {
            i++;
            j++;
            count++;
        }
    }

    while (i < s1.length())
    {
        if (s1[i] == s2[j - 1])
            count++;
        i++;
    }

    while (j < s2.length())
    {
        if (s1[i - 1] == s2[j])
            count++;
        j++;
    }

    cout << count;

    return 0;
}