#include <stdio.h>

typedef struct {
    char name[20];
    int kor;
    int eng;
    int math;
} Score;

int addScore(Score *s)
{
    printf("�̸���? ");
    scanf("%s", s->name);

    printf("�����? ");
    scanf("%d", &s->kor);

    printf("�����? ");
    scanf("%d", &s->eng);

    printf("������? ");
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


