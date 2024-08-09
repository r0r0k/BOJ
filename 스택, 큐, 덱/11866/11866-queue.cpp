#include <iostream>
#include <queue>

using namespace std;

// 1. (1 ~ N) 까지의 값을 queue에 push
// 2. K번째 앞의 값들을 전부 queue에 push(뒤로 보내기) 후 pop
// 3. K번째 값은 print 후 push 하지 않고 pop
// 4. queue.size()가 0이 될 때 까지 반복 (queue.size() == 1 일 때는, ','를 print 하지 않기)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    queue<int> q;

    for (int i = 1; i <= N; i++)
        q.push(i);

    int i;
    int val;
    cout << '<';
    while (q.size() > 0)
    {
        i = K - 1; // K번째 앞의 요소 : (K-1) 번은 뒤로 push 후 pop
        while (i--)
        {
            val = q.front();
            q.push(val);
            q.pop();
        }

        cout << q.front(); // K번째 요소는 출력 후 바로 pop
        q.pop();

        if (q.size() > 0)
            cout << ", ";
    }
    cout << '>';
}