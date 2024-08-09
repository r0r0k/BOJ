#include <iostream>
#include <set>
#include <map>

using namespace std;

// 1. 입력 받은 두 숫자를 소인수 분해
// 2. 입력 받은 두 숫자를 소인수 분해 했을 때, 공통으로 가지는 인수를 저장 (2^3 이어도 2로만 저장해도 됨)
// 3. 두 숫자의 곱을 공통으로 가지는 인수로 나눠주면 최소 공배수 찾을 수 있음

// 여기서 두 숫자의 곱을 공통으로 가지는 인수가 아닌 최대 공약수로 나누어줘야 하므로 이렇게 풀면 안됨

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    int num1, num2;

    set<int> prime_factor1;     // num1의 소인수 : 어쩌피 소인수의 교집합만 나눠주면 되므로 각 소인수의 개수는 중요하지 않아서 set으로 선언
    set<int> prime_factor2;     // num2의 소인수
    map<int, int> intersection; // 소인수의 교집합을 확인하기 위한 map : value가 2이상인 key는 교집합 소인수

    int least_common_multiple; // 최소공배수를 저장할 변수

    for (int i = 0; i < count; i++)
    {
        cin >> num1 >> num2;

        least_common_multiple = num1 * num2;

        int factor = 2;
        while (num1 != 1)
        {
            while (num1 % factor == 0)
            {
                prime_factor1.insert(factor);
                num1 /= factor;
            }
            factor++;
        }

        factor = 2;
        while (num2 != 1)
        {
            while (num2 % factor == 0)
            {
                prime_factor2.insert(factor);
                num2 /= factor;
            }
            factor++;
        }

        for (auto it : prime_factor1)
            intersection[it]++;
        for (auto it : prime_factor2)
            intersection[it]++;

        for (auto it : intersection)
            if (it.second >= 2)
                least_common_multiple /= it.first;

        cout << least_common_multiple << '\n';

        prime_factor1.clear();
        prime_factor2.clear();
        intersection.clear();
    }
}