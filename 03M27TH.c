#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int hw_h1() {
    int n = 0;
    char list_1[16] = {0}, list_2[16] = {0};
    printf("문자를 입력 : ");
    scanf(" %s", &list_1);
    printf("Key값을 입력 : ");
    scanf("%d", &n);
    for (int i = 0; i < strlen(list_1); i++) {
        list_2[i] = list_1[i] + n;
    }
    printf("%s", list_2);
}

int hw_l2() {
    double list[10][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
                        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        list[i][0] = 145 + (rand() % 40);
        list[i][1] = 45 + ((rand() % 4500) / 100.0);
        list[i][2] = (list[i][1] / (list[i][0] * list[i][0])) * 10000;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0) {
                printf("%.0f   ", list[j][i]);
            } else if (i == 1 || i == 2) {
                printf("%.2f ", list[j][i]);
            }

        }
        printf("\n");
    }
}

int main() {
    //hw_h1();
    //hw_l2();
}
