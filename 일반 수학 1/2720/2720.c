#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *cent = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &cent[i]);

    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    int cal;
    for (int i = 0; i < n; i++)
    {
        cal = cent[i] / quarter;
        printf("%d ", cal);
        if (cal > 0)
            cent[i] -= cal * quarter;

        cal = cent[i] / dime;
        printf("%d ", cal);
        if (cal > 0)
            cent[i] -= cal * dime;

        cal = cent[i] / nickel;
        printf("%d ", cal);
        if (cal > 0)
            cent[i] -= cal * nickel;

        cal = cent[i] / penny;
        printf("%d ", cal);
        if (cal > 0)
            cent[i] -= cal * penny;

        printf("\n");
    }

    free(cent);
}