#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "C006.h"
char GNAME[5][20] = {"Bronze", "Silver", "Gold", "Platinum", "Diamond"};
char JNAME[6][20] = {"FreshMen", "Warrior", "Wizard", "Archer", "Assasian", "Pirate"};

void printPlayer(struct Player* p[], int psize)
{
    for (int i = 0; i < psize; i++){
        printf("[%d] %s [%s]\n", i + 1, p[i]->name, JNAME[p[i]->noJob]);
    }
}

int addPlayer(struct Player* p[], int psize)
{
    struct Player* s = (struct Player*)malloc(sizeof(struct Player));
    
    printf(">> Enter the Name > ");
    scanf("%s", s->name);
    
    p[psize] = s;
    return psize + 1;
}

void searchPlayer(struct Player* p[], int psize)
{

}

int deletePlayer(struct Player* p[], int psize)
{

}

void Adventure(struct Player* p[], int psize)
{

}

void savePlayer(struct Player* p[], int psize)
{

}
