#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 이건 set, map의 key를 정렬하는데 사용
// struct cmp
// {
//     bool operator()(const pair<double, int> &a, const pair<double, int> &b)
//     {
//         if (a.first == b.first) // failure_rate가 같다면, stage를 오름차순으로 저장
//             return a.second < b.second;
//         return a.first > b.first; // failure_rate를 내림차순으로 저장
//     }
// };

// vector에 사용
bool cmp(const pair<double, int> &a, const pair<double, int> &b)
{
    if (a.first == b.first) // failure_rate가 같다면, stage를 오름차순으로 저장
        return a.second < b.second;
    return a.first > b.first; // failure_rate를 내림차순으로 저장
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;

    vector<int> arrive_stages(N + 2, 0);   // 각 index stage에 도달한 플레이어 수 저장 : index를 1부터 저장하고, N+1 도 존재하므로 크기는 N+2
    vector<int> not_clear_users(N + 2, 0); // 각 stage에 머물러있는 플레이어 수 저장 : index를 1부터 저장하고, N+1 도 존재하므로 크기는 N+2

    for (auto stage : stages)
    {
        for (int i = 1; i <= stage; i++)
            arrive_stages[i]++;   // 이전 stage에는 전부 도착했으므로 모두 ++
        not_clear_users[stage]++; // 해당 스테이지에 도착한 것은 아직 깨지 못한 것이므로 해당 index에 ++
    }

    double failure_rate; // 실패율

    // vector<pair<double, int>, cmp> rates; vector에는 이렇게 불가능
    vector<pair<double, int>> rates; // <실패율 : double, stage : int>를 저장하는 vector : sort시 index가 바뀌므로 pair로 저장

    for (int i = 1; i <= N; i++)
    {
        if (arrive_stages[i] == 0) // 해당 stage에 도달한 사람이 없으면 0으로 나눌 수 없으므로 미리 failure_rate를 0으로 설정
            failure_rate = 0;
        else
            failure_rate = (double)not_clear_users[i] / (double)arrive_stages[i]; // 값이 int이므로 double로 형변환 해줘야함
        rates.push_back(make_pair(failure_rate, i));
    }

    sort(rates.begin(), rates.end(), cmp); // cmp는 실패율을 내림차순으로 저장, 실패율이 같은 경우 stage를 오름차순으로 저장

    for (auto it : rates)
        answer.push_back(it.second); // it.first : failure_rate, it.second : stage

    return answer;
}