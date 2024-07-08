#include <iostream>

using namespace std;

int gcd(int big, int small)
{
    if (small == 0)
        return big;
    else
        return gcd(small, big % small);
}

// 1. 분모의 최대 공배수를 구해서 분모로 설정해주기
// 2. 앞에서 구한 최대 공배수를 각 숫자의 기존 분모로 나눈 값을 분자에 곱해준 후, 다시 더해서 분자의 합 구하기
// 3. 기약분수로 나타내기 위해 다시 계산한 분자 분모의 최대 공약수를 구해서 약분해주기

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n1, n2; // numerator : 분자
    int d1, d2; // denominator : 분모

    cin >> n1 >> d1;
    cin >> n2 >> d2;

    int d_gcd = d1 > d2 ? gcd(d1, d2) : gcd(d2, d1); // 분모의 gcd
    int denominator = d1 * d2 / d_gcd;               // 분모

    n1 *= denominator / d1;
    n2 *= denominator / d2;
    int numerator = n1 + n2; // 분자

    // 분자와 분모를 기약 분수로 나타내기 위해 분자와 분모를 약분해야함
    // 따라서 분자와 분모의 gcd를 구해서 각각 나눠주면 됨
    int n_d_gcd = numerator > denominator ? gcd(numerator, denominator) : gcd(denominator, numerator);

    cout << numerator / n_d_gcd << " " << denominator / n_d_gcd;
}