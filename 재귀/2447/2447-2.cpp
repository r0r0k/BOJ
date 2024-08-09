#include <iostream>

using namespace std;

// 이렇게 하면 논리는 맞을지 모르지만, 출력을 할 때, 줄바꿈때매 양쪽으로 붙어서 출력이 안됨..
void print_star(int number)
{
    if (number == 3)
    {
        cout << "***\n* *\n***";
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (i != 5) // 가운데를 제외하고 나머지는 (N/3) 패턴으로 채우기
        {
            print_star(number / 3);
            if (i != 9 && i % 3 == 0)
                cout << "\n";
        }

        else // 가운데는 (N/3) X (N/3) 크기의 공백을 가지는 정사각형
        {
            int size = (number / 3) * (number / 3);
            for (int j = 1; j <= size; j++)
            {
                cout << " ";
                if (j != size && j % (number / 3) == 0)
                    cout << "\n ";
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int number; // 3 <= number < 3^8
    cin >> number;

    print_star(number);
    return 0;
}