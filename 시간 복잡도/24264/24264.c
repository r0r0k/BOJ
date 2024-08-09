#include <stdio.h>

int main()
{
    long int n; // 1 <= n <= 500,000 이므로 n^2은 long int(8bytes)가 되야함
    scanf("%ld", &n);

    printf("%ld\n2", n * n); // O(n^2)
}