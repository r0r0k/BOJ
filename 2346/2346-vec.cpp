#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;
    vector<int> moves(count + 1); // 1부터 N까지 move값을 저장하기 위한 vector
    vector<int> vec;              // 1부터 N까지 풍선 번호를 저장하는 vector

    for (int i = 1; i <= count; i++)
    {
        cin >> moves[i]; // index 1 ~ count 까지 move값 저장
        vec.push_back(i);
    }

    int number;
    int move;
    int index = 0;

    while (vec.size() > 0)
    {
        number = vec[index];
        cout << number;

        move = moves[number];
        vec.erase(vec.begin() + index);

        if (vec.size() > 0)
        {
            cout << " ";
            if (move > 0)
            {
                index--;
                index = (index + move) % vec.size();
            }

            else if (move < 0)
            {
                // 아래 코드가 없으면 move가 vec.size()를 넘어가는 경우 index 자체가 vec.size()를 더해줘도 음수가 나올 수 있음 : move는 -1000도 가능하기 때문
                // 따라서, 아래 코드를 통해 move가 실질적으로 왼쪽으로 몇번 이동해야 하는지 구해야함
                move = abs(move) % vec.size();
                index = (index - move + vec.size()) % vec.size();
            }
        }
    }
}