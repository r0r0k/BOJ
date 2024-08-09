#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width, height;
    int buf; // 개행문자 처리를 위한 변수

    scanf("%d %d", &height, &width);
    char **matrix = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++)
    {
        matrix[i] = malloc(sizeof(char) * width);
        // scanf("%s", matrix[i]); // 1. 이거 써주면 아래처럼 안하고 이걸로 바로 가능, 훨씬 간단함 %s는 앞에 남아있는 개행문자를 무시하기 때문
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                getchar();
                // scanf("%d", &buf);
                // 2. 이거 여기서 안해주면 LF(Line Feed, 10)가 %c에 걸려서 해줘야함, %d와 %c는 공백, 탭, 개행문자도 받기 때문
                // 근데 여기서 buf 값을 출력해보면 10이 아닌 이상한 값이 들어있음
                // 그 이유는 %d는 정수가 나올때까지 개행문자를 무시하며 받는데, 정수가 나오지 않으면 그 문자를 buf에 넣지 않고 입력 버퍼에서 삭제시키기 때문

                // 사실 %d는 좋은 방법은 X
            }
            scanf(" %c", &matrix[i][j]); // " %c"를 쓰면 개행문자를 무시하고 받음. "%c"는 개행 문자를 받음
            // scanf(" %c", &matrix[i][j]); // 3. 이렇게 쓰면 %d로 안빼줘도 됨
        }
    }

    int count1, count2; // 맨앞 문자가 W일때와 B일 때 바꿔야 할 횟수 (비교하기 위해 2개 문자 사용)

    int cmp = 8 * 8;                      // 비교 값을 저장해서 다음 turn에도 이어가기 위해
    for (int i = 0; i <= height - 8; i++) // height - 8까지 8x8 matrix를 이동하면서 체크
    {
        for (int j = 0; j <= width - 8; j++)
        {
            // 시작점이 'W'로 시작하는 경우
            count1 = 0;
            for (int k = i; k < i + 8; k++) // 항상 for문 범위 조심하자. k < i + 8이 아니라 k < 8 이라고 써서 몇시간을 날림
            {
                for (int l = j; l < j + 8; l++) // 아래 조건문 2개씩 합쳐도 됨 (합이 짝이냐 홀이냐에 따라)
                {
                    if (k % 2 == 0 && l % 2 == 0) // (짝, 짝)
                        if (matrix[k][l] != 'W')
                            count1++;
                    if (k % 2 == 0 && l % 2 != 0) // (짝, 홀)
                        if (matrix[k][l] != 'B')
                            count1++;
                    if (k % 2 != 0 && l % 2 == 0) // (홀, 짝)
                        if (matrix[k][l] != 'B')
                            count1++;
                    if (k % 2 != 0 && l % 2 != 0) // (홀, 홀)
                        if (matrix[k][l] != 'W')
                            count1++;
                }
            }

            if (cmp > count1)
                cmp = count1;

            // 시작점이 'B'로 시작하는 경우
            count2 = 0;
            for (int k = i; k < i + 8; k++)
            {
                for (int l = j; l < j + 8; l++)
                {
                    if (k % 2 == 0 && l % 2 == 0)
                        if (matrix[k][l] != 'B')
                            count2++;
                    if (k % 2 == 0 && l % 2 != 0)
                        if (matrix[k][l] != 'W')
                            count2++;
                    if (k % 2 != 0 && l % 2 == 0)
                        if (matrix[k][l] != 'W')
                            count2++;
                    if (k % 2 != 0 && l % 2 != 0)
                        if (matrix[k][l] != 'B')
                            count2++;
                }
            }

            if (cmp > count2)
                cmp = count2;
        }
    }

    for (int i = 0; i < height; i++)
        free(matrix[i]);
    free(matrix);

    printf("%d", cmp);
}