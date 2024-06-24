#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *stack;
    int size;
} Stack;

void pop(Stack *s)
{
    s->size--;
}

void push(Stack *s, int input)
{
    s->stack[s->size] = input;
    s->size++;
}

int main()
{
    int n;
    scanf("%d", &n);

    Stack s;
    s.stack = malloc(sizeof(int) * n);
    s.size = 0;

    int input = 0;
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &input);
        if (input == 0 && s.size > 0)
            pop(&s);
        else if (input != 0)
        {
            push(&s, input);
        }
    }

    int sum = 0;
    for (int i = 0; i < s.size; i++)
    {
        sum += s.stack[i];
    }
    printf("%d", sum);
}