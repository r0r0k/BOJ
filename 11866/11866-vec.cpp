#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    // 배열이 아니라 vector로 사이즈 자체를 바꿔줘야함
    vector<int> queue;

    for (int i = 1; i <= N; i++)
        queue.push_back(i);

    int index = -1; // index는 0부터 시작하기 때문에 K번째를 계산하기 위해 미리 -1을 해줌

    cout << '<';
    while (queue.size() > 0)
    {
        index = (index + K) % queue.size();

        cout << queue[index];
        if (queue.size() > 1)
            cout << ", ";

        queue.erase(queue.begin() + index);
        index--;
    }

    cout << '>';
}