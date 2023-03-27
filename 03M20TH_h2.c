#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 적당히 큰 수 정하기 시작
    int random;
    srand(time(NULL));
    random = 100 + rand() % 100 + 1;
    printf("random : %d", random);
    // 적당히 큰 수 정하기 끝

    // 적탕히 큰 수 이상의 소수 찾기 시작
    int count = 0, plag = 0, first_prime, second_prime;
    while (count != 2) {
        plag = 0;
        random = random + 1;
        for (int i = 1; i < random; ++i) {
            if (random % i == 0) {
                plag = plag + 1;
            }
        }
        if (plag == 0) {
            count = count + 1;
            if (count == 1) {
                first_prime = random;
            } else {
                second_prime = random;
            }
        }
    }
    printf("\nfirst_prime / second_prime : %d / %d",first_prime, second_prime);
    // 적탕히 큰 수 이상의 소수 찾기 끝

    printf("\nN (first_prime * second_prime) : %d", first_prime * second_prime);
    printf("\nfai(N) (first_prime * second_prime) : %d", (first_prime - 1) * (second_prime - 1));

    /*
    // fai(N)보다 작고 서로소인 정수중 가장 작은 정수 찾기 시작
    int number = 2;
    count = 0;
    while (count == 0) {
        plag = 0;
        for (int i = 1; i < number; ++i) {
            if (number % i == 0) {
                plag = plag + 1;
            }
        }
        if (plag == 0) {
            printf("%d",number);
        }
    }
     */
}
