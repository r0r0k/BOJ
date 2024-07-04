#include <stdio.h>

// brute-force를 사용하지 않고 풀이
int main()
{
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    // x의 계수를 맞추기 위해
    int x_a = a * d;
    int y_b = b * d;
    int cons_c = c * d;

    int x_d = d * a;
    int y_e = e * a;
    int cons_f = f * a;

    // x를 없앴다고 가정하고, y의 coefficient와 constant를 계산
    int coef_y = y_b - y_e;
    int cons = cons_c - cons_f;

    // x, y의 solution을 계산
    // 정수가 아닌 해를 계산하기 위해서는 double로 형 변환이 필요
    // double인 해를 구할 때, operator가 "/"인 경우 operand도 전부 double로 형 변환이 필요함 (+,-,%)는 상관X
    // 추가적으로 아래처럼 double을 %d로 출력하면 0이 출력됨 (%f는 괜찮음)
    double y = (double)cons / (double)coef_y;
    double x = (double)(cons_f - y_e * y) / (double)x_d;

    // 소수점을 버리고 정수로 출력하려면 int로 형변환 필요
    printf("%d %d", (int)x, (int)y);

    // int i = 3;
    // int j = 2;

    // double k = i - j;

    // printf("\n%d %f %lf", k, k, k);
}