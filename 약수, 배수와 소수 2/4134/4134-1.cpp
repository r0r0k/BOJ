#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(long int number)
{
    int range = sqrt(number);
    for (int i = 2; i <= range; i++) // 만약 종료 조건을 i * i <= number로 쓰면 i가 매우 커지는 경우 i * i에 시간이 많이 들어서 TLE 발생
        if (number % i == 0)
            return false;

    return true;
}

// sqrt(number) 까지만 검사해줘도 약수는 대칭이므로, 시간을 O(n)에서 O(sqrt(n))까지 줄일 수 있음
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
            while (!is_prime(number))
                number++;
            cout << number << '\n';
        }
    }
}