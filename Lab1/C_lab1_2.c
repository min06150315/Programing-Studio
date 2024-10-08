#include <stdio.h>

int main()
{
    int person[4][3];
    int sum[3] = {};
    float ratio[3] = {};
    int i, j = 0;

    printf("Check room (Men)\n");
    for (i = 0; i < 2; i++){
        for (j = 0; j < 3; j++){
            printf("Room #%d0%d > ", i + 1, j + 1);
            scanf("%d", &person[i][j]);
            sum[0] = sum[0] + person[i][j];
            sum[2] = sum[2] + person[i][j];
        }
    }
        
    printf("Check room (Women)\n");
    for (i = 2; i < 4; i++){
        for (j = 0; j < 3; j++){
            printf("Room #%d0%d > ", i + 1, j + 1);
            scanf("%d", &person[i][j]);
            sum[1] = sum[1] + person[i][j];
            sum[2] = sum[2] + person[i][j];
        }
    }
    ratio[0] = (float)sum[0] / 24 * 100;
    ratio[1] = (float)sum[1] / 24 * 100;
    ratio[2] = (float)sum[2] / 48 * 100;

    printf("Check Result\n");
    printf("Men: %d/24 (%.1f%%)\n", sum[0], ratio[0]);
    printf("Women: %d/24 (%.1f%%)\n", sum[1], ratio[1]);
    printf("Total: %d/48 (%.1f%%)\n", sum[2], ratio[2]);

    return 0;
}
