#include <stdio.h>

int main()
{
    int ang1, ang2, ang3;
    scanf("%d%d%d", &ang1, &ang2, &ang3);

    if (ang1 + ang2 + ang3 != 180)
        printf("Error");

    else
    {
        if (ang1 == ang2 || ang1 == ang3 || ang2 == ang3)
            if (ang1 == 60 && ang2 == 60)
                printf("Equilateral");
            else
                printf("Isosceles");
        else
            printf("Scalene");
    }
}