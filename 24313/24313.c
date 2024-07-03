#include <stdio.h>

int main()
{
    int a1, a0, c, n0;
    scanf("%d %d %d %d", &a1, &a0, &c, &n0);

    // f(n0) = a1* n0 + a0, c*g(n0) = c * n0
    // n0 이후 a1의 기울기가 c보다 크면 다시 역전될 수 있으므로 기울기에 대한 c > a1 조건 필요
    // a0가 0일수도 있기 때문에 두 그래프가 일치하는 c == a1 도 가능
    if (a1 * n0 + a0 <= c * n0 && c >= a1)
        printf("1");
    else
        printf("0");
}