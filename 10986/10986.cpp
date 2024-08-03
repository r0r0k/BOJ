#include <iostream>
using namespace std;

int n;
int divisor;             // 어떤 수로 나눌지
int arr[1000001];        // 입력 받은 수를 저장
long interval_count = 0; // 나누어 떨어지는 구간의 개수 (예를 들어, 모든 입력 값이 2이고, divisor가 2이면 n(n + 1) / 2가 int 범위를 넘어서므로 long으로 선언 필요)
long cum_sum[1000001];   // 누적합 (수의 범위가 10^9 이므로, 누적합의 범위가 int를 넘어서므로 long으로 선언 필요)
int cum_modulo[1000001]; // 누적합에 대한 모듈러 연산
long modulo_res[1000];   // modulo_res[i] : 모듈러 연산 결과가 i일 때, 해당 결과값의 개수가 얼마나 존재하는지 (interval_count와 동일한 논리로 long으로 선언 필요)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> divisor;

    int zero_count = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];

        cum_sum[i] = cum_sum[i - 1] + arr[i]; // 누적합 계산 (1-index 이므로 바로 사용 가능)
        cum_modulo[i] = cum_sum[i] % divisor; // 누적합에 대한 모듈러 연산 계산

        modulo_res[cum_modulo[i]]++; // 모듈러 연산 결과 값의 개수를 저장

        // 이렇게 찾으면 O(n^2)의 시간초과 발생
        // else
        // {
        //     for (int j = 1; j < i; j++) // i는 포함하면 안됨
        //     {
        //         if (cum_modulo[i] == cum_modulo[j])
        //             interval_count++;
        //     }
        // }
    }

    interval_count += modulo_res[0] * (modulo_res[0] + 1) / 2; // 연산 결과가 0인 경우 가장 마지막 구간의 0도 포함

    for (int i = 1; i < divisor; i++)                              // 모듈러 연산 결과는 0 ~ (divisor - 1)까지 존재 가능
        interval_count += (modulo_res[i] - 1) * modulo_res[i] / 2; // 연산 결과가 0이 아닌 경우 가장 마지막 구간의 i는 포함 X

    cout << interval_count;
    return 0;
}