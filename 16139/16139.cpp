#include <iostream>
using namespace std;

string str; // 검사할 문자열
int n;      // 질문의 개수
char ch;    // 찾을 문자
int l, r;   // 범위 : [, ]

// 같은 문자열에 대해서 반복해서 검색하기 때문에 누적합 가능
// 이미 이전에 ch 문자에 대해서 누적합을 구했다면, 새로 구할 필요 없이 바로 누적합을 찾아야 TLE 발생 안함
int cum_sum[26][200000];
int prev_flag[26]; // 이전에 해당 문자가 들어왔는지 저장하는 배열

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str >> n;

    while (n--)
    {
        cin >> ch >> l >> r;

        if (prev_flag[ch - 'a'] == true)
            cout << (l == 0 ? cum_sum[ch - 'a'][r] : cum_sum[ch - 'a'][r] - cum_sum[ch - 'a'][l - 1]) << '\n';

        else
        {
            prev_flag[ch - 'a'] = true; // 해당 문자의 누적합을 이미 구했음을 표시

            // 0-index로 해야 l, r을 파악하기 쉽기 때문에 index 0은 미리 초기화해줌
            if (str[0] == ch)
                cum_sum[ch - 'a'][0] = 1;

            for (int i = 1; i < str.length(); i++) // 다음에 같은 문자에 대해 더 큰 r이 들어올 수 있으므로 전체 문자열에 대한 누적합을 미리 구함
            {
                cum_sum[ch - 'a'][i] = cum_sum[ch - 'a'][i - 1]; // 이전 항의 누적합을 가져옴
                if (str[i] == ch)                                // 문자를 찾은 경우
                    cum_sum[ch - 'a'][i]++;                      // 누적합 + 1
            }

            // l == 0 인 경우, (l - 1)은 segfault가 나기 때문에 cum_sum[r]만 출력해줘야함
            // l != 0 인 경우, l, r 번째 문자를 포함해야 하기 때문에 [r]에서 [l - 1]을 뺴줘야함
            cout << (l == 0 ? cum_sum[ch - 'a'][r] : cum_sum[ch - 'a'][r] - cum_sum[ch - 'a'][l - 1]) << '\n';
        }
    }

    return 0;
}