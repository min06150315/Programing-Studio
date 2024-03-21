#include <stdio.h>

int main(void)
{
    char name[20];
    int kor, eng, math;
    int sum = 0;
    double avg = 0;

    printf("Enter Your Name : ");
    scanf("%s", name);
    
    printf("Enter The KOR Score : ");
    scanf("%d", &kor);
    printf("Enter The ENG Score : ");
    scanf("%d", &eng);
    printf("Enter The MATH Score : ");
    scanf("%d", &math);

    sum = kor + eng + math;
    avg = sum / 3.0;

    printf("%s Student's Scoce is %d and Average is %.2f", name, sum, avg);

    return 0;
}