#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "C006.h"

// 직업 종류
char JNAME[5][20] = {"Warrior", "Wizard", "Archer", "Assassin", "Pirate"};
// 등급 종류
char GNAME[5][20] = {"Bronze", "Silver", "Gold", "Platinum", "Diamond"};

// 플레이어 목록 출력
void printPlayer(struct Player* p[], int psize)
{
    for (int i = 0; i < psize; i++){
        printf("[%d] %s [%s] [Lv.%d] [%d GOLD]\n", i + 1, p[i]->name, JNAME[p[i]->noJob], p[i]->level, p[i]->money);
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
    printf("> Job List >\n");
    for (int i = 0; i < 5; i++){
        printf("[%d] %s  ", i + 1, JNAME[i]);
    }

    int job;
    printf("\n>> Enter the Player's Job (1 ~ 5) > ");
    scanf("%d", &job);
    if (job == 1 || job == 2 || job == 3 || job == 4 || job == 5){
        s->noJob = job - 1;
        s->level = 1;
        s->money = 0;

        p[psize] = s;
        psize++;
    }else {
        printf("Error!! Wrong Number.\n");
    }
    
    return psize;
}

// 이름으로 플레이어 찾기
void searchPlayer(struct Player* p[], int psize)
{
    int count = 0;
    char name[64];

    printf(">> Enter the player name keyword > ");
    scanf("%s", name);

    printf("> Searching (keyword : %s)\n", name);
    for (int i = 0; i < psize; i++){
        if (strstr(p[i]->name, name)){
            printf("[%d] %s [%s] [Lv.%d] [%d GOLD]\n", i + 1, p[i]->name, JNAME[p[i]->noJob], p[i]->level, p[i]->money);
            count++;
        }
    }
    printf("> %d players found.\n", count);
}

// 플레이어 삭제
int deletePlayer(struct Player* p[], int psize)
{
    int no, yesno;
    printf(">> Enter a number of player > ");
    scanf("%d", &no);
    if (no > psize || no < 1){
        printf("> Error!! Wrong Number.\n");
    }else {
        printf("> Player Info.\n");
        printf("[%d] %s [%s] [Lv.%d] [%d GOLD]\n", no, p[no - 1]->name, JNAME[p[no - 1]->noJob], p[no - 1]->level, p[no - 1]->money);
        printf(">> Really Delete? (1:Yes 0:No) > ");
        scanf("%d", &yesno);
        if (yesno == 1){
            strcpy(p[no - 1]->name, p[psize - 1]->name);
            p[no - 1]->noJob = p[psize - 1]->noJob;
            p[no - 1]->money = p[psize - 1]->money;
            p[no - 1]->grade = p[psize - 1]->grade;
            p[no - 1]->level = p[psize - 1]->level;

            psize = psize - 1;
            printf("> Delete Complete.\n");
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
        fprintf(fp, "[%d] %s [%s] [Lv.%d] [%d GOLD]\n", i + 1, p[i]->name, JNAME[p[i]->noJob], p[i]->level, p[i]->money);
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
    scanf("%d", &no);
    if (no > psize || no < 1){
        printf("Error!! Wrong Number.\n");
        exit(-1);
    }
    printf("> Hello, World! %s\n", p[no - 1]->name);
    int menu;
    while (1){
        printf("\n> Menu 1.Player Status 2.Adventure 3.Visit Vilage 4.Rest 5.Shop 6.Change Player 0.Main Menu\n");
        printf(">> Menu? >> ");
        scanf("%d", &menu);

        if (menu == 1){
            printf("> 1.Player Status\n");
            printf("%s [%s] [Lv.%d] [%d GOLD]\n", p[no - 1]->name, JNAME[p[no - 1]->noJob], p[no - 1]->level, p[no - 1]->money);
        }else if (menu == 2){
            printf("> 2.Adventure\n");
            gotoAdventure(p, no, m);
        }else if (menu == 3){
            printf("> 3.Move Vilage\n");
            printf("Welcome to HGU Vilage!!\n");
            printf("Jesus always loves us.\n");
        }else if (menu == 4){
            printf("> 4.Rest\n");
            printf("Player %s take some rest.\n", p[no - 1]->name);
            printf("Player recovered and became claer.\n");
        }else if (menu == 5){
            printf("> 5.Shop\n");
            gotoShop(p, no);
        }else if (menu == 6){
            printf("> 6.Change Player\n");
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
        printf("\n> Menu 1.Move Map 2.Hunting 3.BOSS 4.Back\n");
        printf(">> Menu? >> ");
        scanf("%d", &menu);
        if (menu == 1){
            moveMap(m, count);
        }else if (menu == 2){
            Hunt(p, num);
        }else if (menu == 3){
            fightBoss(p, num);
        }else if (menu == 4){
            printf("Player %s is came back", p[num - 1]->name);
            break;
        }
    }
}

// 상점기능
void gotoShop(struct Player* p[], int num)
{
    int menu;
    int yesno;
    // 플레이어 지갑 상태 보여주기
    printf("> Player Wallet >\n");
    printf("> %s has %d GOLD.\n", p[num - 1]->name, p[num - 1]->money);
    
    // 상점 품목 목록과 상품 구매
    
    while (1){
        printf("\n> Shop Item>\n");
        printf("> [1] Blue Portion (100 GOLD) [2] Red Portion (200 GOLD) [3] White Portion (300 GOLD)\n> [4] EXP Coupon (1000 GOLD) [5] Donate [0] Back > ");
        scanf("%d", &menu);
    
        // 구매 문구
        if (menu == 1){
            if (p[num - 1]->money >= 100){
                p[num - 1]->money -= 100;
                printf("> Purchase successfully\n");
                printf("You purchase Blue Portion.\nIt can help your Intelligence.\n");
            }else{
                printf("> No enough money!!\n");
            }
        }else if (menu == 2){
            if (p[num - 1]->money >= 200){
                p[num - 1]->money -= 200;
                printf("> Purchase successfully\n");
                printf("You purchase Red Portion.\nIt can help your Strength.\n");

            }else{
                printf("> No enough money!!\n");
            }
        }else if (menu == 3){
            if (p[num - 1]->money >= 300){
                p[num - 1]->money -= 300;
                printf("> Purchase successfully\n");
                printf("You purchase White Portion.\nIt is of great benefit to your adventure.\n");
            }else{
                printf("No enough money!!\n");
            }
        }else if (menu == 4){
            if (p[num - 1]->money >= 1000){
                p[num - 1]->money -= 1000;
                printf("> Purchase successfully\n");
                printf("You purchase EXP Coupon.\nYou're level 1 up.\n");
                p[num - 1]->level++;
                printf("[Level Up] Lv.%d -> Lv.%d\n", p[num - 1]->level - 1, p[num - 1]->level);
            }else{
                printf("No enough money!!\n");
            }
        }else if (menu == 5){
            printf("You select the Donate.\nThank you for your service.\n");
            printf("All your money was donated to Handong.\n");
            p[num - 1]->money = 0;
        }else {
            break;
        }
    }
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
    printf("> [%d] %s was selected.\n", menu, p[menu - 1]->name);
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
    printf("You arrived at the %s.\n", m[menu - 1]->mname);

}

// 사냥 기능
void Hunt(struct Player* p[], int num)
{
    // 게임속 재화 습득 및 레벨 상승
    printf("> Found a monster in the wild!!\n");
    printf("> You Defeated it.\n");
    printf("> You got 500 GOLD and 10 experience points and went up 1 level\n");
    p[num - 1]->money += 500;
    p[num - 1]->level++;
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
    printf(">> Enter the BOSS Number > ");
    scanf("%d", &menu);

    // 보스 입장
    printf("> You came to %s's residence.\n", BOSS[menu - 1]);

    // 플레이어 레벨이 보스 레벨 보다 높을시 승리
    if (p[num - 1]->level >= bossLv[menu - 1]){  // 승리시
        printf("> You defeated the evil %s.\n", BOSS[menu - 1]);
        printf("> Player %s was won and got %d GOLD.\n", p[num - 1]->name, reward[menu - 1]);
        p[num - 1]->money += reward[menu - 1];
    }else {  // 패배시
        printf("> The evil %s gave you a final blow.\n", BOSS[menu - 1]);
        printf("> You lost your mind and lost %d GOLD.\n", reward[menu - 1] / 2);
        if (p[num - 1]->money >= reward[menu - 1] / 2){
            p[num - 1]->money -= reward[menu - 1] / 2;
        }else {
            p[num - 1]->money = 0;
        }
    }
}