#include <iostream>

using namespace std;

// for문을 통해 1부터 number까지 모든 수에 대해 나눠보며 나머지를 확인하기 때문에 number가 매우 커져버리면 시간 초과 발생
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    long int number;
    int factor_cnt;

    while (count--)
    {
        cin >> number;

        number--;       // while 처음에 number++을 해주기 때문(탈출할 때 업데이트 하지 않기 위해)
        factor_cnt = 0; // 여기서는 첫번째 입력을 받고 뒤에서 factor_cnt가 2가 되어버려서 바로 while을 탈출하는 것을 방지하기 위해 0으로 설정
        while (factor_cnt != 2)
        {
            factor_cnt = 0; // number를 계속 증가시키며 이전의 number에서 update된 factor_cnt는 지워야 하기 때문에 0으로 설정
            number++;
            for (int i = 1; i <= number; i++)
                if (number % i == 0)
                    factor_cnt++;
        }

        cout << number << '\n';
    }
}