#include <stdio.h>

// 학생 정보를 담아둘 구조체 선언
typedef struct _student{
    char name[20];
    int score[3];
} Student;

//합계리턴 / 학생 1명 포인터 변수
int inputScore(Student *s){
    char title[][20] = {"KOR", "ENG", "MATH"};
    int sum = 0;
    printf("Enter Your Name : ");
    scanf("%s", s->name);

    for (int i = 0; i < 3; i++){
        printf("Enter The %s Score : ", title[i]); 
        scanf("%d", &s->score[i]);
        sum = sum + s->score[i];
    }

    return sum;
}
 
int main(void)
{
    Student s1;
    int sum;
    double avg;

    sum = inputScore(&s1);
    avg = sum / 3.0;

    printf("%s Student's Total Score: %d, Average: %.2f", s1.name, sum, avg);

    return 0;
}