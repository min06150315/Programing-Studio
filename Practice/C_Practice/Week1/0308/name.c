#include <stdio.h>

int main(void)
{
    int int_a;
    char char_a[64];

    // 이름과 분반 입력;
    printf("이름을 입력해주세요: ");
    scanf("%s", char_a);
    printf("분반을 입력해주세요: ");
    scanf("%d", &int_a);

    // 한동대학교 프로그래밍 스튜디오 수업에 오신 
    // 학생분들 환영합니다.
    printf("한동대학교 프로그래밍 스튜디오 수업에 오신\n");
    printf("%s 학생분 환영합니다.\n", char_a);

    // 저는 ''분반에서 공부하고 있습니다. 
    printf("저는 %02d분반에서 공부하고 있습니다.\n", int_a);
    printf("나 %s은(는) 하나님과 사람 앞에서 정직하고 성실하게 과제와 수업을 수행하겠습니다.", char_a);

    return 0;
}