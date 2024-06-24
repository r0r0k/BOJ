#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 입력 받을 단어 개수를 저장하는 변수
    int n;
    scanf("%d", &n);

    // 입력 받을 단어에서 group_word가 아닌 것은 뺴주기 위해 설정
    int group_word_cnt = n;

    // 입력 받을 word를 저장할 변수 (malloc이나 array로 메모리를 할당해줘야함)
    char *word = malloc(sizeof(char) * 101);

    // word에서 다음 char와 이전 char가 같은지 파악하기 위한 벼눗
    int compare;

    // word에 존재하는 각 알파벳이 비연속적으로 등장한 횟수 저장
    int history[26];

    for (int i = 0; i < n; i++)
    {
        // history 초기화
        // strlen 사용 가능
        for (int i = 0; i < sizeof(history) / sizeof(history[0]); i++)
            history[i] = 0;

        // word를 입력 받음
        scanf("%100s", word);

        // word의 알파벳이 이전 알파벳과 다른지 검사
        int j = 0;
        compare = word[0];

        while (word[j] != '\0')
        {
            j++;
            // 만약 알파벳 연속이 끊긴다면 history 1증가 (알파벳이 연속적일때는 계속 진행시키면됨)
            // 만약 같은 알파벳이 2번 불연속적으로 나온다면 history index가 2가 될 것임
            if (compare != word[j])
                // 이전의 알파벳(compare)의 index를 증가시켜줌
                history[compare - 'a']++;
            compare = word[j];
        }

        for (int i = 0; i < sizeof(history) / sizeof(history[0]); i++)
        {
            // history index가 1보다 커지면 불연속적으로 2번 나온거니까 group_word가 아니게 됨
            if (history[i] > 1)
            {
                // 입력받은 word 개수에서 group_word의 개수를 1개 깎아줌
                group_word_cnt--;
                // break 안해주면 word 하나가 2번 연속 계산될 수 있음
                break;
            }
        }
    }
    printf("%d\n", group_word_cnt);
}