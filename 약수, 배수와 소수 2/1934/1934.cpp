#include <iostream>

using namespace std;

// 1. 입력 받은 두 숫자의 최대 공약수를 구함
// 2. 입력 받은 두 숫자의 곱을 최대 공약수로 나누어주면 최소 공배수를 구할 수 있음

int gcd_rec(int big, int small)
{
    if (small == 0)
        return big;
    else
        // 여기서 return을 해줘야 마지막에 small == 0 일 때 return되는 big을 가장 외부 gcd(main에서 호출한 gcd)까지 return되므로 꼭 써줘야함
        return gcd_rec(small, big % small);
}

int gcd(int big, int small)
{
    while (small != 0)
    {
        int tmp = big;
        big = small;
        small = tmp % small;
    }

    return big;

    // while (big % small != 0)
    // {
    //     int tmp = big;
    //     big = small;
    //     small = tmp % small;
    // }

    // return small;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    int num1, num2;

    int greatest_common_divisor; // 최대 공약수를 저장할 변수
    int least_common_multiple;   // 최소공배수를 저장할 변수

    for (int i = 0; i < count; i++)
    {
        cin >> num1 >> num2;
        least_common_multiple = num1 * num2;

        greatest_common_divisor = num1 > num2 ? gcd(num1, num2) : gcd(num2, num1);

        least_common_multiple /= greatest_common_divisor;
        cout << least_common_multiple << '\n';
    }
}