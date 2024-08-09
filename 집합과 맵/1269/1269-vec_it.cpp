#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size1, size2;
    cin >> size1 >> size2;

    vector<int> vec1(size1);
    vector<int> vec2(size2);

    for (int i = 0; i < size1; i++)
        cin >> vec1[i];

    for (int i = 0; i < size2; i++)
        cin >> vec2[i];

    // vector는 set과 달리 입력시 정렬이 되어 있지 않기 때문에 sort를 해줘야함
    // 대신 vector가 훨씬 빠름
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    // vecotr를 쓰면 set에 반해 중복이 존재하는 경우를 생각해서 따로 중복도 제거해줘야 되긴 함
    vec1.erase(unique(vec1.begin(), vec1.end()), vec1.end());
    vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());

    int i = 0;
    int j = 0;
    int v1_size = vec1.size();
    int v2_size = vec2.size();
    int count = 0;

    while (i < v1_size && j < v2_size)
    {
        if (vec1[i] == vec2[j])
        {
            i++;
            j++;
        }

        else if (vec1[i] < vec2[j])
        {
            count++;
            i++;
        }

        else if (vec1[i] > vec2[j])
        {
            count++;
            j++;
        }
    }

    // vec1, vec2 중 어떤 vector가 먼저 끝났을지 모르니 둘다 빼줌 (먼저 끝난건 어쩌피 0이 더해지므로 상관 X)
    count += v1_size - i;
    count += v2_size - j;

    cout << count;
}