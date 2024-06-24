#include <stdio.h>
#include <string.h>

int main()
{

    char words[5][16];
    int i = 5;

    for (int k = 0; k < 5; k++)
    {
        for (int j = 0; j < 16; j++)
        {
            words[k][j] = 0;
        }
        // scanf("%15s", words[k]);
    }

    while (i--)
    {
        // while 조건문에서 i는 1~5까지 가능하고 while 안에서는 i--가 되서 0~4까지 됨
        scanf("%15s", words[4 - i]);
    }

    for (int column = 0; column < 16; column++)
    {
        for (int row = 0; row < 5; row++)
        {
            // row마다 길이가 다를 수 있기 때문에, 위에서 0으로 초기화 (아스키코드 0번은 '\0'과 같음) 하고 0이 나오면 출력x
            if (words[row][column] != 0)
                printf("%c", words[row][column]);
        }
    }
}