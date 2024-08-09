#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    string message;

    unordered_set<string> users; // 인사를 했으면 true로 설정, 처음엔 자동으로 false로 초기화

    int greet_count = 0;
    while (count--)
    {
        cin >> message;
        if (message == "ENTER") // "ENTER"인 경우 새로운 사람이 입장했으므로 모두 인사해야함 : user를 전부 false로 초기화
        {
            users.erase(users.begin(), users.end()); // unordered_set도 마찬가지로 clear()에 버그 있음
            continue;
        }

        else
        {
            auto pair = users.insert(message);
            if (pair.second == true) // 처음에 초기화 될 때는 false임
                greet_count++;
        }
    }

    cout << greet_count;
    return 0;
}