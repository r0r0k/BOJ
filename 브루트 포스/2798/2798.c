#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count;
    int number;

    scanf("%d %d", &count, &number);

    int *cards = malloc(sizeof(int) * count);
    int max = 0;
    int sum;

    for (int i = 0; i < count; i++)
        scanf("%d", &cards[i]);

    for (int i = 0; i < count - 2; i++)
        for (int j = i + 1; j < count - 1; j++)
            for (int k = j + 1; k < count; k++)
            {
                sum = cards[i] + cards[j] + cards[k];
                if (sum <= number && sum > max)
                    max = sum;
            }

    printf("%d", max);

    free(cards);
}