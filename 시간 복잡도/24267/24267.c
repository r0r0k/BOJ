#include <stdio.h>

int main()
{
    long int n; // 1 <= n <= 500,000
    scanf("%ld", &n);

    // 아래처럼 일일히 구하면 시간 초과남
    // long int count = 0;
    // for (int i = 1; i <= n - 2; i++)
    //     for (int j = i + 1; j <= n - 1; j++)
    //         for (int k = j + 1; k <= n; k++)
    //             count++;

    long int complexity = n * (n - 1) * (n - 2) / 6;
    printf("%ld\n3", complexity); // O(n^3)
}