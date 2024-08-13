#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

// 시간초과 : sort는 O(nlogn)이 소요되는데, 평균적으로 n번 sort를 한다고 치면 O(n^2logn)이 되기 때문
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector<int> vec;
    int tmp;
    while (n--)
    {
        cin >> tmp;
        if (tmp == 0)
        {
            if (vec.size() == 0)
                cout << "0" << '\n';
            else
            {
                sort(vec.begin(), vec.end());
                cout << vec.back() << '\n';
                vec.pop_back();
            }
        }
        else
            vec.push_back(tmp);
    }

    return 0;
}