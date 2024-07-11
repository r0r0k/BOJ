#include <stdio.h>
#include <stdlib.h>

void parameter_passing(int *anything)
{
    anything[0] = 1;
}

int main()
{
    int *ptr = malloc(sizeof(int) * 5);
    ptr[0] = 3;

    int arr[5];
    arr[0] = 3;

    parameter_passing(ptr);
    parameter_passing(arr);

    printf("ptr : %d\n", ptr[0]);
    printf("arr : %d\n", arr[0]);
}