#ifndef _C_H_
#define _C_H_

struct Player{
    char name[64];
    int level;
    int exp[100];
    int grade; // 1 ~ 5 grades
    int noJob; // 1 ~ 10 jobs
};

void printPlayer(struct Player* p[], int psize);
int addPlayer(struct Player* p[], int psize);
void searchPlayer(struct Player* p[], int psize);
int deletePlayer(struct Player* p[], int psize);
void Adventure(struct Player* p[], int psize);
void savePlayer(struct Player* p[], int psize);

#endif