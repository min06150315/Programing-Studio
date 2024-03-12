#include <stdio.h>

typedef struct {
    char name[20];
    int number;
    int score[3];
} Score;

int selectMenu()
{
    int menu;
    printf("\n*** Score Menu ***\n");
    printf("1. Read\n");
    printf("2. Create\n");
    printf("3. Update\n");
    printf("4. Delete\n");
    printf("0. End\n");
    printf("=> Menu? ");
    scanf("%d", &menu);

    return menu;
}

int addScore(Score *s)
{
    printf("Number? ");
    scanf("%d", &s->number);

    printf("Name? ");
    scanf("%s", s->name);

    printf("Korean Score? ");
    scanf("%d", &s->score[0]);

    printf("English Score? ");
    scanf("%d", &s->score[1]);

    printf("Math Score? ");
    scanf("%d", &s->score[2]);

    return 1;
}

void readScore(Score s)
{
    int sum = 0;
    double avg = 0;

    if (s.score[0] >= 0 && s.score[1] >= 0 && s.score[2] >= 0){
        sum = s.score[0] + s.score[1] + s.score[2];
        avg = (double)sum / 3.0;
    }else {
        sum = -1;
        avg = -1;
    }
    printf("%10s | %8s | %4s | %4s | %4s | %4s | %5s\n", "Number", "Name", "Kor", "Eng", "Math", "Sum", "Avg");
    printf("%10d | %8s | %4d | %4d | %4d | %4d | %5d\n", s.number, s.name, s.score[0], s.score[1], s.score[2], sum, avg);
}

int updateScore(Score *s)
{
    printf("Update Number?: ");
    scanf("%d", &s->number);

    printf("Update Name? ");
    scanf("%s", s->name);

    printf("Update Korean Score? ");
    scanf("%d", &s->score[0]);

    printf("Update Englsh Score? ");
    scanf("%d", &s->score[1]);

    printf("Update Math Score? ");
    scanf("%d", &s->score[2]);
    
    printf("=> Succsess Update\n");
    return 1;
}

int deleteScore(Score *s)
{
    s->score[0] = -1;
    s->score[1] = -1;
    s->score[2] = -1;

    printf("Success Delete\n");
    return 1;
}

int main(void)
{
    Score s;
    int count, menu;

    while(1){
        menu = selectMenu();
        if (menu == 0)
            break;
        if (menu == 1 || menu == 3 || menu == 4)
            if (count == 0)
                continue;
        if (menu == 1)
            readScore(s);
        else if (menu == 2)
            addScore(&s);
        else if (menu == 3)
            updateScore(&s);
        else if (menu == 4)
            deleteScore(&s);
    }
    return 0;
}