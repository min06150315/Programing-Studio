#include <stdio.h>

int main(void)
{

    int a = 0;
    printf("Enter Tree's size: ");
    scanf("%d", &a);
    
    for (int i = a; i > 0; i--){
        for (int j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}