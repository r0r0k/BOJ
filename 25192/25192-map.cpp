#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    string message;

    // map보다 unordered_map이 `key`의 정렬이 필요 없는 경우 훨씬 빠름 : 96ms vs 28ms
    // search의 경우 해시의 최악(O(n))을 제외하면 O(1) vs O(logn)

    // map<string, bool> users; // 인사를 했으면 true로 설정, 처음엔 자동으로 false로 초기화
    unordered_map<string, bool> users; // 인사를 했으면 true로 설정, 처음엔 자동으로 false로 초기화

    int greet_count = 0;
    while (count--)
    {
        cin >> message;
        if (message == "ENTER") // "ENTER"인 경우 새로운 사람이 입장했으므로 모두 인사해야함 : user를 전부 false로 초기화
        {
            // 1. 이렇게 하면 iterator의 복사본을 가져오므로 실제 it.second에서 iterator의 값을 변화시키지 않음
            // for (auto it : users)
            //     it.second = false;

            // 2. 이렇게 하면 map의 모든 index에 접근해야하기 때문에 TLE 발생
            // for (auto &it : users)
            // {
            //     it.second = false;
            // }

            // 3. 이렇게 하면 아예 map 자체를 날려버리므로 TLE 발생 안함 (이전의 users는 어쩌피 누적 안하니까 저장할 필요 없기 때문)
            // users.clear();

            // 4. 해시를 사용하는 경우 `user.clear();`는 버킷 크기의 시간 복잡도가 발생하는 버그가 있음
            users.erase(users.begin(), users.end());
            continue;
        }

        else
        {
            if (users[message] == false) // 처음에 초기화 될 때는 false임
            {
                greet_count++;
                // !users[message]; // 이걸로는 값만 리턴 가능하고 실제 value 변경은 불가
                users[message] = true; // 이미 인사를 했으므로 true로 변경
            }
        }
    }

    cout << greet_count;
    return 0;
}