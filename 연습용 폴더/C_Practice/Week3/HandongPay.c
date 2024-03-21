/*한동페이 
    Student 50명
    학번    이름    연락처  
    충전횟수    사용횟수    현재 잔액
    충전+   사용-
    학생 / 충전 / 사용

    학생 구조체 선언해봅시다.
    저장할 정보는
    => 학번 / 이름 / 연락처 / 충전 횟수 / 사용횟수 / 현재 잔액

    충전 구조체도 선언해봅시다.
    => no / 금액

    사용 구조체도 선언해봅시다.
    => no / 금액
*/
#include <stdio.h>
#include <string.h>

typedef struct HandongPay {
    char snum[20];
    char sname[20];
    char sphone[20];
    int smoney;
};

typedef struct Plus {
    int no;
    int money;
};

typedef struct Minus {
    int no;
    int money;
};



int main(){
    


    return 0;
}


