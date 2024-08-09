#include <iostream>
#include <vector>

using namespace std;

void test_brank_or_star(int i, int j, int number)
{
    if ((i / (number / 3)) % 3 == 1 && (j / (number / 3)) % 3 == 1)
        // 중간의 (N/3) * (N/3) 정사각형 크기의 공백을 재귀적으로 판단 가능
        // i를 (number / 3)으로 나눈 몫을 3으로 나눈 나머지가 1이면, 3등분 중 중간이 됨
        // 3으로 나눴기 때문에 (number / 3)으로 다시 재귀적으로 나눈 몫을 3으로 나눴을 때의 나머지도 똑같이 1이 되어서, 3등분 중 중간이 되므로 해당 자리는 바로 " " 출력
        cout << " ";

    else if (number == 3)
        // 재귀적으로 (number / 3)을 호출해서 끝까지 공백의 조건에 포함되지 않고 number가 3이 된다면 "*"을 출력
        // number / 3 == 1 으로 해도 되지만, 어쩌피 number가 3의 제곱수이므로 무조건 (n / 3)을 하다 보면 마지막에 3이 나옴
        cout << "*";

    else
        // 계속 재귀적으로 해당 자리가 " "인지 확인
        test_brank_or_star(i, j, number / 3);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int number;
    cin >> number;

    for (int i = 0; i < number; i++) // row
    {
        for (int j = 0; j < number; j++) // column
            test_brank_or_star(i, j, number);
        cout << "\n";
    }

    return 0;
}
