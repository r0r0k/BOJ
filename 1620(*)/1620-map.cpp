#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // map은 단방향 매핑만 가능하기 때문에 도감 번호와 포켓몬 이름 양방향으로 찾으려면 2개의 map이 필요
    map<string, int> m1;
    map<int, string> m2;
    // 또는 벡터나 배열을 선언, set은 오름차순 정렬이 되버리므로 인덱스가 유지되지 않아서 불가능
    vector<string> vec(N + 1); // i = 1부터 시작하므로 index 1부터 들어가서 N+1로 해줌

    string tmp;
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        m1.insert(make_pair(tmp, i));
        m2.insert(make_pair(i, tmp));
        vec[i] = tmp;
        // vec의 크기를 먼저 지정해주면 해당 크기의 vector는 초기화되므로 push_back을 하면 index 0부터가 아닌 N+1 부터 들어가버리게됨
        // push_back을 쓸거면 크기 초기화 X
        // vec.push_back(tmp);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        if (tmp[0] > '0' && tmp[0] <= '9')
        {
            // cout << m2[stoi(tmp)] << '\n';
            cout << vec[stoi(tmp)] << '\n';
        }
        else
            cout << m1[tmp] << '\n';
    }
}