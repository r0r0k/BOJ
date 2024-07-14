#include <iostream>
#include <map>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    cin >> count;

    // 자동으로 정렬되고, 최빈값을 구할 수 있는 map을 선언
    map<int, int> m; // first : value, second : mode

    double mean = 0; // 평균
    int tmp;
    for (int i = 0; i < count; i++)
    {
        cin >> tmp;
        mean += tmp; // +는 int로 해도됨
        m[tmp]++;
    }

    // round는 가장 가까운 정수 찾음 (= 소수점 첫째 자리에서 반올림) : cout에서 알아서 2.0은 2로 출력됨
    // 출력할 때, (int)mean을 하지 않으면, mean이 -0.3일 때, -0으로 출력됨 (mean + 0.0 을 해도 됨)
    mean = round(mean / count);

    int median;                    // 중앙값
    int median_count = 0;          // 중앙값을 구하기 위해 빈도(it.second)를 누적해야함
    int median_found_flag = false; // median을 찾았으면 뒤에서 count를 검사하면 안되기 때문

    int mode_val = 0; // 최빈값을 가지는 value
    int mode = 0;     // 최빈값이 얼마인지 저장
    set<int> s;       // 현재 mode를 저장하는 set : map을 거꾸로 써써 <value, key>로 하면 mode의 중복이 허용안되서 못씀

    int range = 0; // 범위 : (최댓값 - 최솟값)

    int i = 1;        // 최솟값, 최댓값, 중앙값을 찾기 위한 iterator 역할
    for (auto it : m) // 여기선 pair이므로 it.first, m.begin()으로 iterator를 하면 it->first
    {
        if (it.second > mode)
        {
            mode = it.second;
            s.clear();
            s.insert(it.first); // 아래의 조건처럼 최빈값이 같은 경우가 생길 수 있기 때문에 비교하기 위해서
        }
        else if (it.second == mode) // mode가 중복되는 경우 : 사실 map은 정렬되있기 때문에 두번 째로 같아지는 값을 insert하면, 아래에서 바로 vec[1]을 하면 되긴 함
        {
            s.insert(it.first);
        }

        if (i == 1) // 최솟값
            range -= it.first;

        if (i == m.size()) // 최댓값 : 중복이 있을 수 있어서 count와 같게 하면 안됨, 중앙값도 마찬가지
            range += it.first;

        // 중앙값을 이렇게 구하면 각 value가 나온 갯수도 고려해야하는데, 정렬된 순서만 고려하므로 제대로 구할 수 없음
        // if (i == m.size() / 2 + 1) // 중앙값 : count는 홀수이기 때문
        //     median = it.first;

        if (!median_found_flag)
        {
            median_count += it.second;
            if (median_count >= count / 2 + 1)
            {
                median = it.first;
                median_found_flag = true;
            }
        }

        i++;
    }

    if (s.size() > 1)
    {
        // mode_val = *(s.begin() + 1); // vector와 달리 트리로 구현되어 있어서 index 이동하려면 이렇게는 불가
        auto it = s.begin();
        advance(it, 1);
        mode_val = *it;
    }
    else
        mode_val = *(s.begin());

    cout
        << (int)mean << '\n'
        << median << '\n'
        << mode_val << '\n'
        << range << '\n';

    return 0;
}