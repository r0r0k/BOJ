#include <stdio.h>

int main()
{
    int sum = 0;
    int n;
    scanf("%d", &n);
    sum += n;
    scanf("%d", &n);
    sum *= n;
    scanf("%d", &n);
    sum *= n;

    // 각 숫자의 개수를 저장하는 array
    int cnt[10] = {
        0,
    };

    while (sum != 0) // sum이 0이 되면 종료
    {
        cnt[sum % 10]++; // sum % 10은 sum의 일의 자리 숫자를 나타냄 (10^n으로 나누면 뒤에서 n자리 수가 나옴 ex 134 % 100 = 34)
        sum /= 10;       // 다음엔 하나 더 큰 자리 수를 가져오기 위해 10으로 나눠줌 134 / 10 = 13
    }

    for (int i = 0; i < 10; i++)
        printf("%d\n", cnt[i]);
}