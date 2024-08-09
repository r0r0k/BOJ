#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int count;     // 봉지의 총 개수
    int remaining; // 봉지를 쓰고 남은 설탕 양

    for (int i = n / 5; i >= 0; i--)
    {
        count = i;
        remaining = n - (5 * i); // n % i 를 하면 안됨 (i--를 해준 후 i가 작아지므로)

        count += remaining / 3; // 5kg 봉지를 다 쓰고 남은 설탕(remaining)에 3kg 봉지를 사용
        if (remaining % 3 == 0) // 3kg 봉지를 써서 전부 설탕을 담은 경우 : remaning % 3 == 0
        {
            printf("%d", count);
            return 0; // return 대신 break로 하면 -1을 출력하지 않기 위해 flag 변수를 하나 설정해줘야함
        }
    }
    printf("-1");
}