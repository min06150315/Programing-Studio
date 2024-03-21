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

void readScore(Score s)
{
    int sum = s.kor + s.eng + s.math;
    double avg = sum / 3.0;

    printf("%8s %4d %4d %4d %5d %5.1f\n", s.name, s.kor, s.eng, s.math, sum, avg);
}

int main(void)
{
    int result = 0;
    Score s;

    result = addScore(&s);

    printf("Name  Kor  Eng  Math  Sum  Avg \n");
    readScore(s);

    return 0;
}