#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int kor;
    int eng;
    int math;
} Score;

int addScore(Score *s)
{
    printf("이름은? ");
    scanf("%s", s->name);

    printf("국어는? ");
    scanf("%d", &s->kor);

    printf("영어는? ");
    scanf("%d", &s->eng);

    printf("수학은? ");
    scanf("%d", &s->math);

    return 1;
}

void readScore(Score s)
{
    int sum = s.kor + s.eng + s.math;
    double avg = sum / 3.0;

    printf("%8s %4d %4d %4d %5d %5.1f\n", s.name, s.kor, s.eng, s.math, sum, avg);
}

void listScore2(Score *s[], int count)
{
    printf("\nNo Name Kor Eng Math Sum Avg\n");
    printf("================================\n");
    for (int i = 0; i < count; i++){
        if (s[i]->kor == -1)
            continue;
        printf("%2d", i + 1);
        readScore(*s[1]);
    }
    printf("\n");
}

int main()
{
    int count = 0, menu;
    int result = 0;
    
    Score *sp[100];
    int index = 0;

    result = addScore(&sp[index]);

    while(1){
        menu = selectMenu();
        if (menu == 0)
            break;
        if (menu == 1 || menu == 3 || menu == 4)
            if (count == 0)
                continue;
        if (menu == 1){
            printf("Name Kor Eng Math Sum Avg \n");
            readScore(sp);
        }
        else if (menu == 2){
            sp[index] = (Score *)malloc(sizeof(Score));
            count += addScore(sp[index++]);
        }
        else if (menu == 3)
            updateScore(&sp);
        else if (menu == 4)
            deleteScore(&sp);
    }
    return 0;
}