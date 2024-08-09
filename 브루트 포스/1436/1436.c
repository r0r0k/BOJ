#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int name = 666;
    int cmp;       // 어떤 수가 종말 수인지 비교하기 위한 변수
    int six_count; // 연속적인 6의 개수를 저장하는 변수

    while (n != 1) // n == 1일 때는 666이므로 제외하고, n--를해서 n == 1이 될 때 까지 반복
    {
        name++; // brute-force로 계속 name을 증가시키며 만족하는 name 찾기
        six_count = 0;
        cmp = name;
        while (cmp != 0)
        {
            if (cmp % 10 == 6)
                six_count++;
            else // 연속하는 6을 찾기 위해 자릿수에서 6이 나오지 않으면 바로 six_count를 0으로 초기화해줌
                six_count = 0;

            if (six_count == 3) // 연속하는 6이 3개 나온 경우
            {
                n--; // n을 하나 빼주고 반복문 탈출
                break;
            }
            else // 아직 연속하는 6이 3개 나오지 않은 경우 name이 0이 될 때까지 자릿수 계속 나누며 확인
                cmp /= 10;
        }
    }

    printf("%d", name);
}