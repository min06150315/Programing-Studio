#ifndef _C_H_
#define _C_H_

struct Player{
    char name[64];
    int level;
    int exp[100];
    int grade; // 1 ~ 5 grades
    int noJob; // 1 ~ 10 jobs
};
char GNAME[5][20] = {"Bronze", "Silver", "Gold", "Platinum", "Diamond"};
char JNAME[5][20] = {"Warrior", "Wizard", "Archer", "Assasian", "Pirate"};

void printPlayer(struct Player* p[], int psize);
int addPlayer(struct Player* p[], int psize);
void searchPlayer(struct Player* p[], int psize);
int deletePlayer(struct Player* p[], int psize);
void Adventure(struct Player* p[], int psize);
void savePlayer(struct Player* p[], int psize);

#endif