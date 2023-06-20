#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int grade[20] = {}, cost[20] = {}, potential[20] = {};


void grade_and_potential(int i, int random){
    grade[i] = random;
    potential[i] = ((cost[i] + 1) * random) + random - 1;
}

void display_print(int i){
    if (i == 1){
        printf("%s ", "일반");
    } else if (i == 2){
        printf("%s ", "고급");
    } else if (i == 3){
        printf("%s ", "희귀");
    } else if (i == 4){
        printf("%s ", "전설");
    }
}

int main() {
    // 난수생성함수
    srand(time(NULL));

    // 카드분배
    for (int i = 0; i < 20; i++){
        // 비용 정하기
        int in_for_cost = (rand() % 3) + 1;
        cost[i] = in_for_cost;

        // 등급과 능력치 구하기
        int in_for_percent = rand() % 101;
        if (0 <= in_for_percent && in_for_percent <= 11){
            grade_and_potential(i, 4);
        } else if (12 <= in_for_percent && in_for_percent <= 30){
            grade_and_potential(i, 3);
        } else if (31 <= in_for_percent && in_for_percent <= 59) {
            grade_and_potential(i, 2);
        } else if (60 <= in_for_percent && in_for_percent <= 100) {
            grade_and_potential(i, 1);
        }
    }

    // 등급출력
    printf(" 등급: ");
    for (int i = 0; i < 20; i++){
        display_print(grade[i]);
    }
    // 비용룰력
    printf("\n 비용: ");
    for (int i = 0; i < 20; i++){
        printf("  %d ", cost[i]);
    }
    // 능력치
    printf("\n능력치: ");
    for (int i = 0; i < 20; i++){
        if (potential[i] < 10) {
            printf("  %d ", potential[i]);
        } else {
            printf(" %d ", potential[i]);
        }
    }

    // 카드선택
    printf("\n");
    int ans = 0;
    while (1) {
        printf("\n몇 번째 카드를 가져가시겠습니까?: ");
        scanf(" %d", &ans);
        if (1 <= ans && ans <= 20){
            break;
        }
        // 입력버퍼 문자제거
        while (getchar() != '\n');
        printf("\n유효한 값을 입력하십시오.");
    }

    // 선택카드 출력
    display_print(grade[ans-1]);
    printf("카드\n비용: %d\n능력치: %d", cost[ans-1], potential[ans-1]);
}
