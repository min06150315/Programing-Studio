#include <stdio.h>

/*학생의 정보를 받을 구조체를 선언해보세요
학번 이름
국어, 영어, 수학 점수

1. 성적을 등록하는 함수(createScore)
파라미터는 구조체(Student) / 결과갑은 int 값으로!(성공은 1 / 실패는 0)
점수가 0점 미만이거나 100점 초과일때 입력 불가하게 제약

2. 학생의 성적을 조회하는 함수(readScore)
파라미터는 구조체(Student) / 결과갑은 int 값으로!(성공은 1 / 실패는 0)

3.학생의 성적을 수정하는 함수(updateScore)
파라미터는 구조체(Student) / 결과갑은 int 값으로!(성공은 1 / 실패는 0)

4.학생의 성적을 삭제하는 함수(deleteScore)
파라미터는 구조체(Student) / 결과갑은 int 값으로!(성공은 1 / 실패는 0)
삭제하기 직전에 진짜 삭제 여부를 물어보고 사용자에게 대답을 들어볼 것!

5. 메인함수 실행하면, 어떤 기능 실핼할지 정하는 기능 만들어주세요!

6. 추가가 되지 않은 상태에서 수정이나 삭제가 되지 않도록 제약을 두는 기능

메인함수에서는
성적 등록 하고, 바로 조회라는 기능 넣어주세요!
*/

typedef struct{
    char name[20];
    int number;
    int score[3];
} Student;

int createScore(Student *s)
{
    char title[][20] = {"Kor", "Eng", "Math"};

    printf("Enter the studentNumber: ");
    scanf("%d", &s->number);

    printf("Enter the name: ");
    scanf("%s", &s->name);

    for (int i = 0; i < 3; i++){
        printf("Enter the %s score: ", title[i]);
        scanf("%d", &s->score[i]);
    }
    return 1;
}

int readScore(Student s)
{
    int sum = s.score[0] + s.score[1] + s.score[2];
    int avg = sum / 3.0;

    printf("%10s | %8s | %4s | %4s | %4s | %4s | %5s\n");
    printf("%10d | %8s | %4d | %4d | %4d | %4d | %5d\n", s.number, s.name, s.score[0], s.score[1], s.score[2], sum, avg);

    return 1;
}

int updateScore(Student *s)
{
    char title[][20] = {"Kor", "Eng", "Math"};

    for (int i = 0; i < 3; i++){
        printf("Modify the %s Score", title[i]);
        scanf("%d", &s->score[i]);
    }
    return 1;
}

int deleteScore(Student *s)
{
    int menu = 0;
    printf("Really Delete? (Yes: 0  No: 1)");
    scanf("%d", &menu);

    if (menu = 0){
        for (int i = 0; i < 3; i++)
            s->score[i] = -1;
        printf("Complete Delete");
    } else if (menu = 1){
        printf("Not Delete");
        return 0;
    }else
        printf("Error!");
    
    return 1;
}

int selectMenu()
{
    int menu;

    printf("What you want?\n");
    printf("1. Create\n");
    printf("2. Read\n");
    printf("3. Update\n");
    printf("4. Delete\n");
    printf("0. End\n");
    scanf("%d", &menu);

    switch (menu){
        case 1:
            menu = 1;
            break;
        case 2:
            menu = 2;
            break;
        case 3:
            menu = 3;
            break;
        case 4:
            menu = 4;
            break;
        case 0:
            menu = 0;
            break;
        default:
            break;
    }
    return menu;
}

int main(void)
{
    Student s1;
    int menu = 0;
    int result = 0;

    menu = selectMenu();
    if (menu == 1)
        result = createScore(&s1);
    else if (menu == 2)
        readScore(s1);
    else if (menu == 3)
        result = updateScore(&s1);
    else if (menu == 4)
        result = deleteScore(&s1);
    else if (menu == 0)
        return 0;
    
    return 0;
}