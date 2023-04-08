#include <stdio.h>
#include <stdlib.h>

void game_of_31(int* arr, int deadline, int people, int count) {
    count += 1;
    if (deadline == 1) {
        arr[(count - 1) % people] += 1;
        return;
    }
    if (deadline == 2) {
        game_of_31(arr, deadline - 1, people, count);
    } else if (deadline == 3) {
        game_of_31(arr, deadline - 1, people, count);
        game_of_31(arr, deadline - 2, people, count);
    } else {
        game_of_31(arr, deadline - 1, people, count);
        game_of_31(arr, deadline - 2, people, count);
        game_of_31(arr, deadline - 3, people, count);
    }
}

int main() {
    int deadline = 0, people = 0, count = 0, sum = 0;
    int* arr = 0;
    printf("베스킨라빈스 게임의 벌칙 숫자를 입력하세요 : ");
    scanf(" %d", &deadline);
    printf("베스킨라빈스 게임의 참여 인원을 입력하세요 : ");
    scanf(" %d", &people);
    arr = (int*) malloc(sizeof(int) * people);
    game_of_31(arr, deadline, people, count);
    for (int i = 0; i < people; i++) {
        sum += arr[i];
    }
    printf("\n벌칙 숫자는 %d , 참여 인원은 %d 일 경우 총 %d 가지의 경우의 수가 있으며\n각 플레이어가 걸릴 경우의 수와 확률은 다음과 같습니다.\n\n", deadline, people, sum);
    for (int i = 0; i < people; i++) {
        printf("%d번째 플레이어 : %d (%.2f%%)\n", i + 1, arr[i],(double)arr[i]/sum*100);
    }
    free(arr);
    arr = NULL;
    return 0;
}
