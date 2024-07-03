#include <stdio.h>

int main()
{
    long int n; // 1 <= n <= 500,000
    scanf("%ld", &n);

    // long int count = 0;
    // for (int i = 1; i <= n - 1; i++)
    //     for (int j = i + 1; j <= n; j++)
    //         count++;

    // printf("%ld\n2", count); // O(n^2)

    printf("%ld\n2", n * (n - 1) / 2); // O(n^2)
}