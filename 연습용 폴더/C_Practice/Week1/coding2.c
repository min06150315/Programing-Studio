#include <stdio.h>

int main(void)
{
    char name[20];
    char title[][20] = {"KOR", "ENG", "MATH"};
    int score[3], sum = 0;
    double avg = 0;

    printf("Enter Your Name : ");
    scanf("%s", name);
    
    for (int i = 0; i < 3; i++){
        printf("Enter The %s Score : ", title[i]);
        scanf("%d", &score[i]);
        sum = sum + score[i];
    }

    avg = sum / 3.0;

    printf("%s Student's Scoce is %d \nAnd Average is %.2f.", name, sum, avg);

    return 0;
}