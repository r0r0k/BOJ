#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count;
    scanf("%d", &count);

    int *x = malloc(sizeof(int) * count);
    int *y = malloc(sizeof(int) * count);

    int x_min = 10000;
    int x_max = -10000;

    int y_min = 10000;
    int y_max = -10000;

    for (int i = 0; i < count; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
        if (x[i] <= x_min)
            x_min = x[i];
        if (x[i] >= x_max)
            x_max = x[i];
        if (y[i] <= y_min)
            y_min = y[i];
        if (y[i] >= y_max)
            y_max = y[i];
    }

    printf("%d", (x_max - x_min) * (y_max - y_min));

    free(x);
    free(y);
}