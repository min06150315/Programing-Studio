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

#define SIZE 50

struct HandongPay {
    char snum[20];
    char sname[20];
    char sphone[20];
    int smoney;
};

struct Charge {
    int no;
    int money;
};

struct Use {
    int no;
    int money;
};
int addStudent(struct HandongPay *c[], int size);
void printMyWallet(struct HandongPay *c[], int size);
int chargeHandongPay(struct HandongPay *c[], int size);
int useHandongPay(struct HandongPay *c[], int size);

int main(){
    struct HandongPay *student1[SIZE];
    struct Charge charge[SIZE];
    struct Use use[SIZE];
    int menu;
    int no = 0;
    printf(">> HANDONG PAY >>");

    while(1){
        printf("[1]Add Student [2]My wallet [3]Charge [4]Use [0]Exit\n> Enter a menu >> ");
        scanf("%d", &menu);

        if (menu == 1){
            no = addStudent(student1, no);
        }
        else if (menu == 2){
            printMyWallet(student1, no);
        }
        else if (menu == 3){
            chargeHandongPay(student1, no);
        }
        else if (menu == 4){
            useHandongPay(student1, no);
        }
        else {
            break;
        }
    }
    return 0;
}

int addStudent(struct HandongPay *c[], int size)
{
    printf("Enter the student's number: ");
    scanf("%s", c[size]->snum);
    printf("Enter the student's name: ");
    scanf("%s", c[size]->sname);
    printf("Enter the student's phone number: ");
    scanf("%s", c[size]->sphone);

    return size++;
}
void printMyWallet(struct HandongPay *c[], int size)
{
    
}

int chargeHandongPay(struct HandongPay *c[], int size)
{

}

int useHandongPay(struct HandongPay *c[], int size)
{

}
