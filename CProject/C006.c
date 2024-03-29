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
    int no, yesno;
    printf(">> Enter a number of player >");
    scanf("%d", &no);
    if (no > psize){
        printf("> Error! Wrong number.\n");
    }else {
        printf("> Player Info.\n");
        printf("[%d] %s", no, p[no -1]->name);

        printf(">> Really Delete? (1:Yes 0:No) >");
        scanf("%d", &yesno);
        if (yesno == 1){
            strcpy(p[no - 1]->name, p[psize - 1]->name);
            psize = psize - 1;
        }else if (yesno == 0){
            printf("> Delete Canceled.\n");
        }
    }
    return psize;
}

// 플레이어 목록을 txt파일로 저장하기
void savePlayer(struct Player* p[], int psize)
{
    FILE* fp = NULL;
    fp = fopen("report.txt", "w");
    printf("> All information of players are saved.\n");

    fprintf(fp, "Player List\n");
    for (int i = 0; i < psize; i++){
        fprintf(fp, "[%d] %s (%s)- Lv.%d - Money: %d -  Grade: %s\n", i + 1, p[i]->name, JNAME[p[i]->noJob], p[i]->level, p[i]->money, GNAME[p[i]->grade]);
    }
    fclose(fp);
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
        printf("> Menu 1.Adventure 2.Move Vilage 3.Rest 4.Shop 5.Change Player 0.Quit\n");
        scanf("%d", &menu);

        if (menu == 1){
            printf("> 1.Adventure\n");
            gotoAdventure(p, no, m);
        }else if (menu == 2){
            printf("> 2.Move Vilage\n");
            printf("Welcome to HGU Vilage!!\n");
            printf("Jesus always loves us.\n");
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

// 상점기능
void gotoShop(struct Player* p[], int num)
{
    // 플레이어 지갑 상태 보여주기
    printf("> Player Wallet >\n");
    printf("> %s has %d GOLD.\n", p[num]->name, p[num]->money);
    
    // 상점 품목 목록
    printf("> Shop >\n");
    
    // 
    
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
    // 게임속 재화 습득 및 레벨 상승
    printf("> Found a monster in the wild!!\n");
    printf("> You Defeated it.\n");
    printf("> You got 500 GOLD and 10 experience points and went up 1 level\n");
    p[num]->money += 500;
    p[num]->level++;
}

// 보스전 기능
void fightBoss(struct Player* p[], int num)
{
    char BOSS[5][20] = {"Demien", "Lucid", "Kalos", "Darknell", "Black Mage"};
    int menu;
    int bossLv[5];
    int reward[5];

    // 보스 리스트
    printf("> BOSS List >\n");
    for (int i = 0; i < 5; i++){
        bossLv[i] = (i + 1) * 10;
        reward[i] = (i + 1) * 5000;
        printf("[%d] %s (Lv.%d)\n", i + 1, BOSS[i], bossLv[i]);
    }
    // 원하는 보스 입력
    printf(">> Enter the BOSS > ");
    scanf("%d", &menu);

    // 보스 입장
    printf("> You cam to %s's residence.\n", BOSS[menu - 1]);

    // 플레이어 레벨이 보스 레벨 보다 높을시 승리
    if (p[num]->level >= bossLv[menu - 1]){  // 승리시
        printf("> You defeated the evil %s.\n", BOSS[menu - 1]);
        printf("> Player %s was won and got %d GOLD.\n", p[num]->name, reward[menu]);
        p[num]->money += reward[menu];
    }else {  // 패배시
        printf("> The evil %s gave you a final blow.\n", BOSS[menu - 1]);
        printf("> You lost your mind and lost %d GOLD.\n", reward[menu] / 2);
        if (p[num]->money >= reward[menu] / 2){
            p[num]->money -= reward[menu] / 2;
        }else {
            p[num]->money = 0;
        }
    }
}