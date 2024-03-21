#include <stdio.h>

typedef struct {
    char name[20];
    int kor;
    int eng;
    int math;
} Score;

int main()
{
    Score s1;
    Score kim, hong;
    Score s[10];
    Score*sp = &kim;

    printf("%s", s1.name);
    printf("%d", s[0].kor);
    printf("%d", sp->eng);
}