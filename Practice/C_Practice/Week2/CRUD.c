//  1. 변수의 사용범위
//  2. 구조체 생성, typedef 사용
//  3. 함수 생성하는 방법
//  4. Call by value, Call by reference
//  5. 일반 변수와 포인터 변수의 차이점

#include <stdio.h>

typedef struct {
    char name[20];
    int kor;
    int eng;
    int math;
} Score;

int selectMenu()
{
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);

    return menu;
}

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

int updateScore(Score *s)
{
    printf("이름은? ");
    scanf("%s", s->name);

    printf("국어는? ");
    scanf("%d", &s->kor);

    printf("영어는? ");
    scanf("%d", &s->eng);

    printf("수학은? ");
    scanf("%d", &s->math);
    
    printf("=> 수정성공!\n");
    return 1;
}

int deleteScore(Score *s)
{
    s->kor = -1;
    s->eng = -1;
    s->math = -1;

    return 1;
}

int main(void)
{
    Score s;
    int count = 0, menu;

    while(1){
        menu = selectMenu();
        if (menu == 0)
            break;
        if (menu == 1 || menu == 3 || menu == 4)
            if (count == 0)
                continue;
        if (menu == 1){
            printf("Name Kor Eng Math Sum Avg \n");
            readScore(s);
        }
        else if (menu == 2)
            addScore(&s);
        else if (menu == 3)
            updateScore(&s);
        else if (menu == 4)
            deleteScore(&s);
    }
    return 0;
}