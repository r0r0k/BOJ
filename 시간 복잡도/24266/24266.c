#include <stdio.h>

int main()
{
    long int n; // 1 <= n <= 500,000
    scanf("%ld", &n);

    printf("%ld\n3", n * n * n); // O(n^3)
}