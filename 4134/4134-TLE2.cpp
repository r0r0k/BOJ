#include <iostream>

using namespace std;

// 중간에 약수가 하나라도 나오면 break를 해줬지만 여전히 TLE
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    long int number;
    while (count--)
    {
        cin >> number;

        if (number <= 2) // 아래 반복문에서 i는 2부터 number -1까지 순회할 것이므로 number가 2일 때는 미리 출력해줌
            cout << '2' << '\n';

        else
        {
            while (1)
            {
                int cmp = number;
                for (int i = 2; i < number; i++)
                {
                    if (number % i == 0) // 2와 number -1 사이에 약수가 하나라도 있으면 number++을 해주고 반복문 종료
                    {
                        number++;
                        break;
                    }
                }
                if (cmp == number) // for문이 끝나고 나서도 number가 update 되지 않았다면 소수이므로 반복문 탈출
                    break;
            }
            cout << number << '\n';
        }
    }
}