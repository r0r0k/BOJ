```
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
```