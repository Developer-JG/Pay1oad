#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hw_l1() {
    int num, i_ans;
    char c_ans;

    printf("한국인입니까? [(Y) / N] : ");
    scanf(" %c", &c_ans);
    if (c_ans == 'N' || c_ans == 'n') {
        num = 6;
    } else {
        num = 2;
    }

    int plag = 0;
    while (plag == 0) {
        printf("출생년도를 입력하세요 : ");
        scanf(" %d", &i_ans);
        if (num == 2) {
            if (1800 <= i_ans && i_ans <= 2023) {
                plag += 1;
            } else {
                printf("\n입력값이 범위를 벗어났습니다. "
                       "\n입력범위를 1800 ~ 2023 사이로 입력하여 주십시오. \n\n");
            }
        } else if (num == 6){
            if (1900 <= i_ans && i_ans <= 2023) {
                plag += 1;
            } else {
                printf("\n입력값이 범위를 벗어났습니다. "
                       "\n입력범위를 1900 ~ 2023 사이로 입력하여 주십시오. \n\n");
            }
        }
    }
    if (1800 <= i_ans && i_ans <= 1899) {
        num = num - 2;
    } else if (1900 <= i_ans && i_ans <= 1999) {
        num = num;
    } else if (2000 <= i_ans && i_ans <= 2023) {
        num = num + 2;
    }

    printf("성별을 입력하세요? [(M) / F] : ");
    scanf(" %c", &c_ans);
    if (c_ans == 'F' || c_ans == 'f') {
        num = num;
    } else {
        if (num == 0) {
            num = 9;
        } else {
            num = num - 1;
        }
    }

    printf("주민등록번호 뒷자리의 첫 번째 숫자는 %d입니다.\n",num);
}

int hw_l2() {
    int ans;
    printf("주민등록번호 뒷자리의 첫 번째 숫자를 입력하세요. : ");
    scanf(" %d", &ans);
    printf("\n");

    if (ans % 2 == 1) { // ans가 홀수일때
        printf("성별은 남성이고 ");
        if (ans == 9){
            ans = 0;
        } else {
            ans = ans + 1;
        }
    } else { // ans가 짝수일때
        printf("성별은 여성이고 ");
        ans = ans;
    }

    if (ans == 0) {
        printf("19세기 출생자이며 ");
        ans = ans + 2;
    } else if (ans == 2 || ans == 6) {
        printf("20세기 출생자미여 ");
        ans = ans;
    } else {
        printf("21세기 출생자미여 ");
        ans = ans - 2;
    }

    if (ans == 2) {
        printf("대한민국 국적입니다.");
    } else {
        printf("외국 국적입니다.");
    }
}

int hw_l3() {
    int random, i_int;
    srand(time(NULL));
    random = rand() % 100 + 1;
    printf("게임시작\n");

    int plag = 1;
    while (plag != 0) {
        printf("숫자를 입력하세요. : ");
        scanf(" %d", &i_int);
        if (i_int < random) {
            printf("Up\n");
        } else if (i_int > random) {
            printf("Down\n");
        } else {
            printf("\n정답입니다. %d 번 시도하였습니다.", plag);
            plag = -1;
        }
        plag = plag + 1;
    }
}

int hw_l4() {
    for (int i = 1; i <= 9; i++){
        for (int j = 1; j <= 9; j++){
            if (j == 1){
                printf("\n**********\n\n\n**********");
            }
            printf("\n%d * %d = %d", i, j, i * j);
        }
    }
    printf("\n**********\n\n\n**********");
}


int main() {
    //hw_l1();
    //hw_l2();
    //hw_l3();
    //hw_l4();
}
