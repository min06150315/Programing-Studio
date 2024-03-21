#include <stdio.h>

typedef struct {
    char name[20]; // Student Name
    //  int number;
    char snum[20]; // Student Number
    int score[3]; // Three Scores
} Score;

int selectMenu()
{
    //select menu option
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
    char title[][20] = {"Kor", "Eng", "Math"};
    int i = 0;
    int return_val = 1;

    // input student number
    printf("Enter the Student Number: ");
    scanf("%s", s->snum);

    // input student name
    printf("Enter the Name: ");
    scanf("%s", s->name);

    // input kor, eng, math scores
    for (int i = 0; i < 3; i++){
        printf("Enter the %s Score: ", title[i]);
        scanf("%d", &s->score[i]);
        if (s->score[i] < 0 || s->score[i] > 100){
            return_val = 0;
            break;
        }
    }
    return return_val;

    /*
    printf("Number? ");
    scanf("%d", &s->snum);

    printf("Name? ");
    scanf("%s", s->name);

    printf("Korean Score? ");
    scanf("%d", &s->score[0]);

    printf("English Score? ");
    scanf("%d", &s->score[1]);

    printf("Math Score? ");
    scanf("%d", &s->score[2]);

    return 1;
    */
}

int readScore(Score s)
{
    int sum = 0;
    double avg = 0;
    /*
    if (s.score[0] >= 0 && s.score[1] >= 0 && s.score[2] >= 0){
        sum = s.score[0] + s.score[1] + s.score[2];
        avg = (double)sum / 3.0;
    }else {
        sum = -1;
        avg = -1;
    }
    */
    printf("%10s | %8s | %4s | %4s | %4s | %4s | %5s\n", "Number", "Name", "Kor", "Eng", "Math", "Sum", "Avg");
    for (int i = 0; i < 3; i++)
        sum  += s.score[i];
    avg = sum / 3.0;
    printf("%10s | %8s | %4d | %4d | %4d | %4d | %5.2f\n", s.snum, s.name, s.score[0], s.score[1], s.score[2], sum, avg);
}

int updateScore(Score *s)
{
    /*
    printf("Update Number?: ");
    scanf("%d", &s->snum);

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
    */
    char title[][20] = {"Kor", "Eng", "Math"};
    int return_val = 1;
    for (int i = 0; i < 3; i++){
        printf("Update the %s Score?: ", title[i]);
        scanf("%d", &s->score[i]);
        if (s->score[i] < 0 || s->score[i] > 100){
            printf("Wrong Answer");
            return_val = 0;
            break;
        }
    }
    return return_val;
}

int deleteScore(Score *s)
{
    /*
    s->score[0] = -1;
    s->score[1] = -1;
    s->score[2] = -1;
    printf("Success Delete\n");
    return 1;
    */
   int answer;

   printf("Your score delete process!!\n");
   printf("Are you sure?(Yes - 1 / No - 0): ");
   scanf("%d", &answer);
   if (answer == 1){
   } else {
        return 0;
   }
   for (int i = 0; i < 3; i++)
        s->score[i] = -1;
   return 1;
}

int main(void)
{

    /*
    while(1){
        menu = selectMenu();
        if (menu == 0)
            break;
        if (menu == 1 || menu == 3 || menu == 4)
            if (count == 0)
                continue;
        if (menu == 1)
            readScore(s1);
        else if (menu == 2)
            addScore(&s1);
        else if (menu == 3)
            updateScore(&s1);
        else if (menu == 4)
            deleteScore(&s1);
    }
    return 0;
    */
    Score s1;
    int menu = 0, result = 0, count = 0;

    while (1){
        menu = selectMenu();
        if (menu == 0)
            break;
        if (menu == 1 || menu == 3 || menu == 4){
            if (count == 0){
                printf("No!\n");
                continue;
            }
        }
        if (menu == 1)
            readScore(s1);
        else if (menu == 2){
            result = addScore(&s1);
            if (result > 0)
                count = 1;
        } else if (menu == 3)
            result = updateScore(&s1);
        else if(menu == 4){
            result = deleteScore(&s1);
            if (result > 0)
                count = 0;
        }
    }
} 