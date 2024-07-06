#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    // 1. deep copy : 472ms

    vector<int> vec(count);
    for (int i = 0; i < count; i++)
        cin >> vec[i];

    vector<int> copy(vec); // deep copy
    // vector<int> copy = vec;   // deep copy
    // vector<int> &copy = vec;  // shallow copy
    // vector<int> *copy = &vec; // shallow copy

    // 2. 크기 지정 안하고 대입 : 464ms, 미리 크기 지정을 안해주므로 메모리 사용량은 2500KB 정도 더 쓰게 됨

    // vector<int> vec;
    // vector<int> copy;
    // int tmp;
    // for (int i = 0; i < count; i++)
    // {
    //     cin >> tmp;
    //     vec.push_back(tmp);
    //     copy.push_back(tmp);
    // }

    // 3. 크기 지정 후 대입 : 464ms

    // vector<int> vec(count);
    // vector<int> copy(count);
    // int tmp;
    // for (int i = 0; i < count; i++)
    // {
    //     cin >> tmp;
    //     vec[i] = tmp;
    //     copy[i] = tmp;
    // }

    sort(copy.begin(), copy.end());
    copy.erase(unique(copy.begin(), copy.end()), copy.end()); // 중복 제거

    // 아래는 copy에서 vec의 index를 찾는 과정에서 for문을 통한 선형탐색이나, find 함수를 통한 선형탐색이 아닌
    // lower_bound 함수를 통한 이진 탐색을 하기 때문에 시간초과 발생 안함

    // vector<int>::iterator it;
    for (int i = 0; i < count; i++) // vec을 선형 순회
    {
        // auto는 타입 추론, 위에서 처럼 vector<int>::iterator로 안써도 됨
        // lower_bound는 3번째 argument 이상 값이 처음으로 나오는 iterator를 return함 : iterator를 return하므로 바로 cout 불가능
        auto it = lower_bound(copy.begin(), copy.end(), vec[i]);

        // distance는 iterator의 index를 return
        cout << distance(copy.begin(), it) << " ";

        // 아래 처럼 한줄로 가능
        // cout << distance(copy.begin(), lower_bound(copy.begin(), copy.end(), vec[i])) << " ";
    }

    // 아래는 둘다 선형탐색이므로 시간 초과

    // for (const auto &val : vec)
    // {
    //     auto it = find(copy.begin(), copy.end(), val);
    //     cout << distance(copy.begin(), it) << " ";
    // }

    // int size = copy.size();
    // for (int i = 0; i < count; i++) // vec을 선형 순회
    // {
    //     for (int j = 0; j < size; j++) // copy를 선형 순회하며 vec[i] == copy[j] 찾기
    //         if (vec[i] == copy[j])
    //         {
    //             cout << size - j - 1 << " ";
    //             break;
    //         }
    // }
}
