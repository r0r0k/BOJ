#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count, price; // 동전 종류, 가격
    cin >> count >> price;

    int *coins = new int[count];
    for (int i = 0; i < count; i++) // 동전 종류 입력
        cin >> coins[i];

    int i = count - 1;  // 오름차순으로 입력을 받았기 때문에 마지막 인덱스부터 시작
    int coin_count = 0; // 사용한 coin의 개수 (종류 상관X)
    while (price > 0)   // price가 0보다 클 때 진행
    {
        while (price / coins[i] > 0) // 현재 index의 코인으로 나눠질 때 까지 계속 반복
        {
            coin_count += price / coins[i]; // 몫만큼 코인 개수 추가
            price %= coins[i];              // price를 현재 index의 코인 가격으로 나눈 나머지로 업데이트
        }
        i--; // 반복문이 끝났으면 다음 index로 이동 : A1은 1이므로 마지막에 전부 나눠짐
    }

    cout << coin_count;
    delete[] coins;
    return 0;
}