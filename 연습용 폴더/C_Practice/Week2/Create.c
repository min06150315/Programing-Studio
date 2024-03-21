#include <stdio.h>

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

int main(void)
{
    int result = 0;
    Score s;

    result = addScore(&s);

    return 0;
}


