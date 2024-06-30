#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);

    int result = 3;

    for (int i = 1; i < n; i++)
    {
        result += pow(2, i);
    }

    printf("%d", result * result);
}