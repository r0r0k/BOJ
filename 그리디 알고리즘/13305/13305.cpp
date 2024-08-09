#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int city_price[100001]; // 각 도시의 리터당 기름 가격을 저장하는 배열
int dist[100001];       // 각 도시간의 거리를 저장하는 배열 : i는 i와 (i + 1) 사이의 거리

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n - 1; i++)
        cin >> dist[i];

    for (int i = 1; i <= n; i++)
        cin >> city_price[i];

    long res = 0;             // 리터당 가격은 최대 10억이므로, 결과값은 int overflow가 날 수 있어서 long으로 해줘야함
    long min_price = INT_MAX; // 아래에서 long으로 변환하려면 한쪽이 long이어야 하므로 min_price를 long으로 선언

    for (int i = 1; i <= n; i++)
    {
        if (min_price > city_price[i])
            min_price = city_price[i];

        res += min_price * dist[i];
        // res += long(min_price) * dist[i]; // min_price를 int로 선언한 경우
    }

    cout << res;
    return 0;
}