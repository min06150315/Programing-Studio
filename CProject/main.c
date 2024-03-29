// 자유 주제 CRUD프로그램 제작
// Create / Read / Update / Delete / Search / Save
// 주제 : CRUD를 활용한 간단한 RPG 게임 만들기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "C006.h"

int main()
{
    int no;
    int count = 0;
    struct Player* player[50];
    printf(">> INSERT COIN >>\n");
    printf("> Enter the player's name: ");
    scanf("%s", player[count]->name);
    count++;
    player[count]->noJob = 0;
    printf("> Welcome to the My world %s!!\n", player[count]->name);

    while (1){
        printf("\n> Menu 1.Player List 2.Add Player 3.Search Player 4.Delete Player 5.Go Adventure 6.Save 0.Quit\n");
        printf(">> Menu? >>");
        scanf("%d", &no);

        if (no == 1){
            printf("> 1.Player List (%d players)\n", count);
            printPlayer(player, count);
        }else if (no == 2){
            printf("> 2.Add Player\n");
            count = addPlayer(player, count);
        }else if (no == 3){
            printf("> 3.Search Player\n");
            searchPlayer(player, count);
        }else if (no == 4){
            printf("> 4.Delete Player\n");
            count = deletePlayer(player, count);
        }else if (no == 5){
            printf("> 5. Let's go to the Adventure\n");
            Adventure(player, count);
        }else if (no == 6){
            printf("> 6. Save\n");
            savePlayer(player ,count);
        }else {
            break;
        }
    }
    return 0;
}