#include <iostream>
#include <unordered_set>

using namespace std;

// 1. ChongChong이 들어온 이후에 춤이 시작되므로, 그 전에는 set에 저장할 필요 X
// 2. ChongChong이 들어오면 ChongChong과 같이 입력받은 user를 dancing에 insert 후 flag 설정
// 3. flag가 설정되면, 새로 들어오는 user마다 dancing set에 있는지 확인해서 있으면 둘다 dancing set에 넣음

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    unordered_set<string> dancing_users; // 현재 춤추고 있는 user들을 저장 : vector 대신 이진 탐색과 중복 처리를 위해 unordered_set 사용

    string user1, user2;
    bool chong_flag = false; // 만약 Chong이 아직 안들어왔는데 계속 search를 하면 overhead이기 때문

    while (count--)
    {
        cin >> user1 >> user2;
        if (chong_flag) // chong_flag가 없을 때는 search 안하게 하려고 의도했는데, 사실 이때는 dancing_users가 어쩌피 비어있어서 큰 overhead가 없긴함
        {
            if (dancing_users.find(user1) != dancing_users.end() ||
                dancing_users.find(user2) != dancing_users.end())
            {
                dancing_users.insert(user1);
                dancing_users.insert(user2);
            }
        }

        if (user1 == "ChongChong" || user2 == "ChongChong")
        {
            chong_flag = true;
            dancing_users.insert(user1);
            dancing_users.insert(user2);
        }
    }

    cout << dancing_users.size();
    return 0;
}