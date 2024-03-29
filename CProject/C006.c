#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "C006.h"


// 플레이어 목록 출력
void printPlayer(struct Player* p[], int psize)
{
    for (int i = 0; i < psize; i++){
        printf("[%d] %s [%s]\n", i + 1, p[i]->name, JNAME[p[i]->noJob]);
    }
}

// 플레이어 추가
int addPlayer(struct Player* p[], int psize)
{
    // Dynamic Allocation
    struct Player* s = (struct Player*)malloc(sizeof(struct Player));
    
    // 유저에게 새로운 플레이어의 이름 입력받기
    printf(">> Enter the Name > ");
    scanf("%s", s->name);

    // 직업 종류를 보여주고 유저에게 새로운 플레이어의 직업 입력받기
    printf("> Job List >");
    for (int i = 0; i < 5; i++){
        printf("[%d] %s\t", i + 1, JNAME[i]);
    }
    int menu;
    printf(">> Enter the Player's Job (1 ~ 5) > ");
    scanf("%d", &menu);
    s->noJob = menu;

    p[psize] = s;
    return psize + 1;
}

// 이름으로 플레이어 찾기
void searchPlayer(struct Player* p[], int psize)
{
    int count = 0;
    char name[64];

    printf(">> Enter the player name > ");
    scanf("%s", name);

    printf("> Searching (keyword : %s)\n", name);
    for (int i = 0; i < psize; i++){
        if (strstr(p[i]->name, name)){
            printf("[%d] %s [%s]\n", i + 1, p[i]->name, JNAME[p[i]->noJob]);
            count++;
        }
    }
    printf("> %d players found.\n", count);
}

// 플레이어 삭제
int deletePlayer(struct Player* p[], int psize)
{
    int no;
    printf(">> Enter a number of player >");
    scanf("%d", &no);
    if (no > psize){
        printf("> Error! Wrong number.\n");
    }else {
        prntf("> Player Info.\n")
    }
    return psize;
}

// 플레이어 목록을 txt파일로 저장하기
void savePlayer(struct Player* p[], int psize)
{

}

// 게임 시작 함수
void startGame(struct Player* p[], int psize, struct Map* m[])
{
    int no;
    printf("> Player List\n");
    printPlayer(p, psize);
    printf(">> Select the player > ");
    scanf("%d", no);

    int menu;
    while (1){
        printf("> Hello, World! %s\n", p[no]->name);
        printf("> Menu 1.Adventure 2.Move 3.Rest 4.Shop 5.Change Player 0.Quit\n");
        scanf("%d", &menu);

        if (menu == 1){
            printf("> 1.Adventure\n");
            gotoAdventure(p, no, m);
        }else if (menu == 2){
            printf("> 2.Move\n");
            Move(p, no);
        }else if (menu == 3){
            printf("> 3.Rest\n");
            printf("> Player %s [%s]recovered with a break", p[no]->name, JNAME[p[no]->noJob]);
        }else if (menu == 4){
            printf("> 4.Shop\n");
            gotoShop(p, no);
        }else if (menu == 5){
            printf("> 5.Change Player\n");
            no = changePlayer(p, psize);
        }else {
            break;
        }
    }
}

// 모험을 떠나기
void gotoAdventure(struct Player* p[], int num, struct Map* m[])
{
    int count = loadMap(m);
    int menu;
    while (1){
        printf("> Menu 1.Move 2.Hunting 3.BOSS 4.Back\n");
        scanf("%d", &menu);
        if (menu == 1){
            moveMap(m, count);
        }else if (menu == 2){
            gotoHunt(p, num);
        }else if (menu == 3){
            fightBoss(p, num);
        }else if (menu == 4){
            printf("%s [%s] is came back", p[num]->name, JNAME[p[num]->noJob]);
            break;
        }
    }
}

// 이동하기
void Move(struct Player* p[], int num)
{

}

// 상점기능
void gotoShop(struct Player* p[], int num)
{
    
}

// 플레이어 변경
int changePlayer(struct Player* p[], int psize)
{
    int menu;
    // 플레이어 목록 다시 보여주기
    printf("> Player List >\n");
    printPlayer(p, psize);

    // 유저에게 플레이어 넘버 입력받기
    printf(">> Select Player Number > ");
    scanf("%d", &menu);

    // 플레이어 넘버 선택
    printf("> [%d] %s was selected.\n", menu, p[menu]->name);
    return menu;

}

// txt파일에 있는 맵 목록을 불러오기
int loadMap(struct Map* m[])
{
    int count = 0;
    FILE* fp = NULL;

    // 맵 파일 읽고 dynamic allocation 된 구조체에 저장
    fp = fopen("Map.txt", "r");
    while (!feof(fp)){
        m[count] = (struct Map*)malloc(sizeof(struct Map));
        int r = fscanf(fp, "%d %s", &(m[count]->no), m[count]->mname);
        if (r < 2) break;
        count++;
    }
    fclose(fp);
    return count;
}

// 불러온 맵들 중 하나를 골라서 이동하기
void moveMap(struct Map* m[], int msize)
{
    int menu;
    // 맵 목록 보여주기
    for (int i = 0; i < msize; i++){
        printf("[%d] %s\n", m[i]->no, m[i]->mname);
    }
    // 유저에게 입력 받기
    printf(">> Select the Map number> ");
    scanf("%d", &menu);

    // 맵으로 이동하는 문구 출력
    printf("> %s\n", m[menu - 1]->mname);

}

// 사냥 기능
void Hunt(struct Player* p[], int num)
{

}

// 보스전 기능
void fightBoss(struct Player* p[], int num)
{
    
}