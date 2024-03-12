//  1. ������ ������
//  2. ����ü ����, typedef ���
//  3. �Լ� �����ϴ� ���
//  4. Call by value, Call by reference
//  5. �Ϲ� ������ ������ ������ ������

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
    printf("\n*** �������� ***\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);

    return menu;
}

int addScore(Score *s)
{
    printf("�̸���? ");
    scanf("%s", s->name);

    printf("�����? ");
    scanf("%d", &s->kor);

    printf("�����? ");
    scanf("%d", &s->eng);

    printf("������? ");
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
    printf("�̸���? ");
    scanf("%s", s->name);

    printf("�����? ");
    scanf("%d", &s->kor);

    printf("�����? ");
    scanf("%d", &s->eng);

    printf("������? ");
    scanf("%d", &s->math);
    
    printf("=> ��������!\n");
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