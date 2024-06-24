#include <stdio.h>
#include <stdlib.h>

int main()
{
    float credit;
    char grade[3];
    char subject[51];

    float credit_sum = 0;
    float grade_sum = 0;
    while (scanf("%50s %f %2s", subject, &credit, grade) != EOF)
    {
        if (grade[0] == 'P')
            continue;

        credit_sum += credit;

        if (grade[0] == 'A')
        {
            grade_sum += credit * 4.0;
            if (grade[1] == '+')
                grade_sum += credit * 0.5;
        }

        if (grade[0] == 'B')
        {
            grade_sum += credit * 3.0;
            if (grade[1] == '+')
                grade_sum += credit * 0.5;
        }

        if (grade[0] == 'C')
        {
            grade_sum += credit * 2.0;
            if (grade[1] == '+')
                grade_sum += credit * 0.5;
        }

        if (grade[0] == 'D')
        {
            grade_sum += credit * 1.0;
            if (grade[1] == '+')
                grade_sum += credit * 0.5;
        }
    }
    printf("%f\n", grade_sum / credit_sum);
}