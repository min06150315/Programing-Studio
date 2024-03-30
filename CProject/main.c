// 자유 주제 CRUD프로그램 제작
// Create / Read / Update / Delete / Search / Save
// 주제 : CRUD를 활용한 간단한 RPG 게임 만들기
// 제목 : Min's mini RPG Game

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "C006.h"

int main()
{
    int menu;
    int count = 0;
    struct Player* player[50];
    struct Map* map[50];

    // 메모리 동적 할당
    for (int i = 0; i < 50; i++) {
        player[i] = (struct Player*)malloc(sizeof(struct Player));
        map[i] = (struct Map*)malloc(sizeof(struct Map));
    }
    // 게임 첫 시작
    printf(">> INSERT COIN >>\n");
    printf(">> Enter the player's name: ");
    scanf("%s", player[count]->name);
    player[count]->money = 0;
    player[count]->level = 1;
    
    printf("> Job List >\n");
    printf("> [1] Warrior  [2] Wizard  [3] Archer  [4] Assassin  [5] Pirate >\n");
    printf(">> Enter the Player's Job (1 ~ 5) > ");
    int job;
    scanf("%d", &job);
    player[count]->noJob = job - 1;

    printf("> Welcome to the My world %s!!\n", player[count]->name);
    count++;

    while (1){
        printf("\n> Menu 1.Player List 2.Add Player 3.Search Player 4.Delete Player 5.Game Start 6.Save Report 0.Quit\n");
        printf(">> Menu? >> ");
        scanf("%d", &menu);

        if (menu == 1){
            printf("> 1.Player List (%d players)\n", count);
            printPlayer(player, count);
        }else if (menu == 2){
            printf("> 2.Add Player\n");
            count = addPlayer(player, count);
        }else if (menu == 3){
            printf("> 3.Search Player\n");
            searchPlayer(player, count);
        }else if (menu == 4){
            printf("> 4.Delete Player\n");
            count = deletePlayer(player, count);
        }else if (menu == 5){
            printf("> 5.Game Start!!\n");
            startGame(player, count, map);
        }else if (menu == 6){
            printf("> 6.Save Report\n");
            savePlayer(player ,count);
        }else {
            break;
        }
    }
    return 0;
}