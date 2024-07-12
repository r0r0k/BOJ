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
        move = moves[number];
        vec.erase(vec.begin() + index);

        cout << number;
        if (vec.size() > 0)
        {
            cout << " ";
            if (move > 0)
            {
                index--;
                index = (index + move) % vec.size();
            }

            else if (move < 0)
                index = (index - abs(move) + vec.size()) % vec.size();
        }
    }
}