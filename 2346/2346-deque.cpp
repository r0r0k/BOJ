#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<int> dq;
    int count;
    cin >> count;
    vector<int> vec(count + 1); // move값을 저장하기 위한 vector

    for (int i = 1; i <= count; i++)
    {
        cin >> vec[i];   // index 1 ~ count 까지 move값 저장
        dq.push_back(i); // 1 ~ count까지 값 push
    }

    int move;
    int number;
    while (dq.size() > 0)
    {
        number = dq.front();
        dq.pop_front();

        cout << number;
        if (dq.size() > 0)
        {
            cout << " ";
            move = vec[number];
            if (move > 0)
            {
                for (int i = 0; i < move - 1; i++) // (move - 1) 번 만큼
                {
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
            }

            else if (move < 0)
            {
                for (int i = 0; i < abs(move); i++) // move 번 만큼 (절댓값 해줘야 하는거 주의)
                {
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
            }
        }
    }
}