#include <stdio.h>

int main()
{
    char b[10];
    char a = 50;
    scanf("%s", b);  // %s는 정수도 string으로 해석하기 때문에 전부 읽어올 수 있음
    scanf("%c", &a); // %s가 뒤의 개행문자는 안버리니까 %c로 개행문자를 읽어와서 a는 10이 됨
    printf("%s", b);
    printf("%d", a);
}