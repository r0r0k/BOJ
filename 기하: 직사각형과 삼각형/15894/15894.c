#include <stdio.h>

int main()
{
    unsigned int count;
    scanf("%u", &count);
    printf("%u", count * 4); // 40억까지므로 unsigned나 long로 써줘야함
}