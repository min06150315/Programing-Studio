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
#include <stdlib.h>
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
void printMyWallet(struct HandongPay *c[], struct Charge *s1[], struct Use *s2[], int size);
void chargeHandongPay(struct HandongPay *c[], struct Charge *s[], int size);
void useHandongPay(struct HandongPay *c[], struct Use *s[], int size);

int main(){
    struct HandongPay *student1[SIZE];
    struct Charge charge[SIZE];
    struct Use use[SIZE];
    int menu;
    int no = 0;
    printf(">> HANDONG PAY >>");

    while(1){
        printf("[1]Add Student [2]My wallet [3]Charge [4]Use [0]Exit\n> Enter a menu > ");
        scanf("%d", &menu);

        if (menu == 1){
            no = addStudent(student1, no);
        }
        else if (menu == 2){
            printMyWallet(student1, charge, use, no);
        }
        else if (menu == 3){
            chargeHandongPay(student1, charge, no);
        }
        else if (menu == 4){
            useHandongPay(student1, use, no);
        }
        else {
            break;
        }
    }
    return 0;
}

int addStudent(struct HandongPay *c[], int size)
{
    printf("> Enter the student's number: ");
    scanf("%s", c[size]->snum);
    printf("> Enter the student's name: ");
    scanf("%s", c[size]->sname);
    printf("> Enter the student's phone number: ");
    scanf("%s", c[size]->sphone);

    return size++;
}
void printMyWallet(struct HandongPay *c[], struct Charge *s1[], struct Use *s2[], int size)
{
    printf("> %s's Wallet\n", c[size]->sname);
    printf("> Currnt Money: %d\n", c[size]->smoney);
    printf("> Charge Count: \n");
    printf("> Use Count: \n");
}

void chargeHandongPay(struct HandongPay *c[], struct Charge *s[], int size)
{
    int menu = 0;
    int money;
    
    while(1){
        printf("> Do you want to CHARGE HandongPay? (Yes: 1 / No: 0) >");
        scanf("%d", &menu);
        if (menu == 1){
            printf("> How do you want to CHARGE money? >");
            scanf("%d", &money);
            s[size]->money = money;
            s[size]->no = s[size]->no + 1;
            printf("Complete Charge!!");
        }else {
            break;
        }
    }
    for (int i = 0; i < s[size]->no; i++){
        c[size]->smoney = c[size]->smoney + s[i]->money;
    }
}

void useHandongPay(struct HandongPay *c[], struct Use *s[], int size)
{
    int menu = 0;
    int money;

    
}