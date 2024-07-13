#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    string message;
    map<string, int> users;

    int enter_count = 0; // 현재까지 enter해서 새로 들어온 참가자 수
    int greet_count = 0; // 인사말이 나온 횟수
    while (count--)
    {
        cin >> message;
        // 과거에 "ENTER"를 해서 들어온 user에 대해 전부 누적해서 인사를 해야된다고 생각했음
        // 실제는 마지막 "ENTER"에게만 인사하면 되서 해당 코드는 맞지 않긴함
        if (message == "ENTER")
        {
            enter_count++;
            continue;
        }

        else
        {
            while (users[message] < enter_count) // 만약 누적된 "ENTER" user에게 아직 인사를 하지 않았다면, while으로 전부 인사
            {
                greet_count++;
                users[message]++;
            }
        }
    }

    cout << greet_count;
    return 0;
}