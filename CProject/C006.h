#ifndef _C_H_
#define _C_H_

// 플레이어 구조체
struct Player{
    char name[64];
    int level; // player level
    int noJob; // 1 ~ 10 jobs
    int money; // player's game money
    int grade; // 1 ~ 5 grades
};

// 맵 구조체
struct Map{
    int no; // map num
    char mname[64]; // map name
};

// 직업 종류
char JNAME[5][20] = {"Warrior", "Wizard", "Archer", "Assasian", "Pirate"};

void printPlayer(struct Player* p[], int psize);
int addPlayer(struct Player* p[], int psize);
void searchPlayer(struct Player* p[], int psize);
int deletePlayer(struct Player* p[], int psize);
void savePlayer(struct Player* p[], int psize);

void startGame(struct Player* p[], int psize, struct Map* m[]);
void gotoAdventure(struct Player* p[], int num, struct Map* m[]);
void Move(struct Player* p[], int num);
int changePlayer(struct Player* p[], int psize);
int loadMap(struct Map* m[]);
void moveMap(struct Map* m[], int msize);
void Hunt(struct Player* p[], int num);
void fightBoss(struct Player* p[], int num);

#endif