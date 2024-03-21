#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
// 학생의 정보를 받을 구조체(Student)를 선언해보세요.
학번, 이름
국어, 영어, 수학 점수 (100점 만점)

1. 성적을 등록하는 함수 (createScore)
파라미터는 구조체(Student) / 결과값은 int 값으로!(성공은 1 / 실패는 0)

2. 학생의 성적을 조회하는 함수 (readScore)
파라미터는 구조체(Student) / 결과값은 int 값으로!(성공은 1 / 실패는 0)

3. 학생의 성적을 수정하는 함수 (updateScore)
파라미터는 구조체(Student) / 결과값은 int 값으로!(성공은 1 / 실패는 0)

4. 학생의 성적을 삭제하는 함수 (deleteScore)
파라미터는 구조체(Student) / 결과값은 int 값으로!(성공은 1 / 실패는 0)
*삭제하기 직전에 진짜 삭제 여부를 물어보고 사용자에게 대답을 들어볼 것!

5. 메인함수 실행하면, 어떤 기능 실행할지 정하는 기능 만들어주세요.
*입력한 정보가 없다면, 조회/수정/삭제 가 안되도록 제한해주세요.

!!20240315 - 1
여러개의 정보를 입력할 수 있도록 구성해보세요
배열변수로 도전!!
전체 리스트를 보는 함수(listScore)도 만들어보세요!!

수정 해보겠습니다.
번호 입력하면 번호 불러와서
그 번호에 해당하는 정보 수정

1~100 번 이외의 번호를 입력해도 되어서 잘못 입력하면 에러가 나와서
이미 지워진 번호를 입력해도 진행이 되므로 
이것에 대비

!!20240315 - 2
여러개의 정보를 입력할 수 있도록 구성해보세요 
포인터 배열로 구현해보세요

createScore 부터 구현해보아요
리스트 조회
수정 / 삭제 구현
*/
//구조체 선언
typedef struct _student {
    char snum[20]; //학번
    char name[20]; //이름
    int score[3]; //성적 3개
} Student;
//

int selectMenu(){
    int menu;
    printf("\n*** Score Menu ***\n");
    printf("1. Read\n");
    printf("2. Create\n");
    printf("3. Update\n");
    printf("4. Delete\n");
    printf("0. End\n\n");
    printf("=> Menu? ");
    scanf("%d", &menu);
    return menu;
}

int createScore(Student *s){
    char title[][20] = {"Kor", "Eng", "Math"};
    int i = 0;
    int return_val = 1;
    
    printf("Student Num : ");
    scanf("%s", s->snum);

    printf("Name : ");
    scanf("%s", s->name);

    for(i=0;i<3;i++){
        printf("%s score : ", title[i]);
        scanf("%d", &s->score[i]);
        if(s->score[i] < 0 || s->score[i] > 100){
            printf("Wrong Score!!\n");
            return_val = 0;
            break;
        }
    }
    return return_val;
}

int updateScore(Student *s){
    char title[][20] = {"Kor", "Eng", "Math"};
    int i = 0;
    int return_val = 1;
    
    printf("your score update process!!\n");

    for(i = 0;i < 3; i++){
        printf("%s score : ", title[i]);
        scanf("%d", &s->score[i]);
        if(s->score[i] < 0 || s->score[i] > 100){
            printf("Wrong Score!!\n");
            return_val = 0;
            break;
        }
    }
    return return_val;
}

int deleteScore(Student *s){
    int i = 0;
    int t_answer;

    printf("your score delete process!!\n");
    printf("Are you sure?(Yes - 1/ No - 0) : ");
    scanf("%d", &t_answer);
    if(t_answer == 1){ 
    } else {
        return 0;
    }

    for(i=0;i<3;i++){
        s->score[i] = -1;
        free(s);
    }
    return 1;
}

int readScore(Student s, int count){
    /*
    printf("%10s | %8s | %4s | %4s | %4s | %5s | %5s\n",
        "StudentNum", "Name", "Kor", "Eng", "Math", "Sum", "Avg"
        );
    */
    int sum = 0, i = 0;
    double avg;
    for(i = 0; i < 3; i++){
        sum += s.score[i];
        //printf("%4d %4d\n", sum, s.score[i]);
    }
    avg = sum / 3.0;
    printf("%2s | %10s | %8s | %4d | %4d | %4d | %5d | %5.1f\n",
    count ,s.snum, s.name, s.score[0], s.score[1], s.score[2], sum, avg
    );
}
void listScore(Student *s, int count)
{
    printf("%2s | %10s | %8s | %4s | %4s | %4s | %5s | %5s\n",
        "No", "StudentNum", "Name", "Kor", "Eng", "Math", "Sum", "Avg"
        );

    for (int i = 0; i < count; i++){
        readScore(*s, count);
    }
    count++;
}
int selectScore(Student *s, int count)
{
    int menu = 0;
    printf("Really Delete? (Yes: 1 / No: 0)");
    scanf("%d", &menu);

    return menu;
}

int main(void){
    
    //  Student s1;
    Student *slist[100];
    
    int menu = 0, result = 0, count = 0;
    int index = 0;
    int no = 0;

    while(1){
        menu = selectMenu();
        if(menu == 0) {
            //종료!
            break;
        }

        if(menu == 1 || menu ==3 || menu == 4) {
            //조회, 수정, 삭제
            if(count == 0) {
                //자료가 없을때는 입력만 가능!
                printf("no!!\n");
                continue;
            }
        }
        
        if(menu == 1){
            //  readScore(slist[index]);
            listScore(slist, index);
        } else if(menu == 2) {
            result = createScore(&slist[index]);
            if(result > 0){
                count = 1;
            }
        } else if(menu == 3) {
            result = updateScore(&slist[index]);
        } else if(menu == 4) {
            result = deleteScore(&slist[index]);
            no = selectScore(slist, index);
            if(result > 0){
                count = 0;
            }
        }
    }
    return 0;
}