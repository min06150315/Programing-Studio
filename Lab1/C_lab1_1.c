#include <stdio.h>

int main()
{
    int size;
    int stars, blank1, blank2;
    int i, j;

    printf("Enter the trophy's size: ");
    scanf("%d", &size);

    // part 1
    blank1 = 0;
    blank2 = size * 2 - 2;

    for (i = 0; i < size; i++){
        for (j = 0; j < blank1; j++)
            printf(" ");
        printf("*");

        for (j = 0; j < blank2; j++)
            printf(" ");
        printf("*");

        printf("\n");
        blank1 ++;
        blank2 = blank2 - 2;
    }
    // part 2
    for ( i = 0; i < size; i++){
        for (j = 0; j < size * 2; j++)
            printf("*");
        printf("\n"); 
    }
    // part 3
    blank1 = 0;
    stars = size * 2;

    for (i = 0; i < size; i++){
        for (j = 0; j < blank1; j++)
            printf(" ");

        for (j = 0; j < stars; j++)
            printf("*");
        
        printf("\n");
        blank1++;
        stars = stars - 2;
    }
    
    // part 4
    for (i = 0; i < size * 2; i++)
        printf("*");
    
    return 0;
}
