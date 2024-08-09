#include <stdio.h>

// 범위의 앞, 뒤, (뒤-앞) 의 규칙성 전부 파악해보기
int main()
{
    int number;
    scanf("%d", &number);

    int compare = 2;
    int count = 1;

    while (number - compare >= 0)
    {
        compare += 6 * count;
        count++;
    }
    printf("%d", count);
}