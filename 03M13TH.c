#include <stdio.h>

int hw_l1() {
    char num1;
    int num2;
    printf("char : ");
    scanf("%d", &num1);
    printf("char echo : ");
    printf("%d", num1);
    printf("\n");
    printf("int : ");
    scanf("%d", &num2);
    printf("int echo : ");
    printf("%d", num2);
}

int hw_l2(){
    int mon, sold_mon;
    printf("자판기에 입력된 돈 : ");
    scanf("%d", &mon);
    printf("구매한 상품의 총 가격 : ");
    scanf("%d", &sold_mon);
    if (mon >= sold_mon) {
        printf("\n거스름돈 : 총 ");
        mon = mon - sold_mon;
        printf("%d", mon);
        printf("\n\n");

        int count = 0;
        for (int i = 0; 50000 <= mon; ++i) {
            mon -= 50000;
            count += 1;
        }
        printf("50000원 지폐 : ");
        printf("%d", count);
        printf(" 장");

        printf("\n");
        count = 0;
        for (int i = 0; 10000 <= mon; ++i) {
            mon -= 10000;
            count += 1;
        }
        printf("10000원 지폐 : ");
        printf("%d", count);
        printf(" 장");

        printf("\n");
        count = 0;
        for (int i = 0; 5000 <= mon; ++i) {
            mon -= 5000;
            count += 1;
        }
        printf("5000원 지폐 : ");
        printf("%d", count);
        printf(" 장");

        printf("\n");
        count = 0;
        for (int i = 0; 1000 <= mon; ++i) {
            mon -= 1000;
            count += 1;
        }
        printf("1000원 지폐 : ");
        printf("%d", count);
        printf(" 장");

        printf("\n");
        count = 0;
        for (int i = 0; 500 <= mon; ++i) {
            mon -= 500;
            count += 1;
        }
        printf("500원 동전 : ");
        printf("%d", count);
        printf(" 개");

        printf("\n");
        count = 0;
        for (int i = 0; 100 <= mon; ++i) {
            mon -= 100;
            count += 1;
        }
        printf("100원 동전 : ");
        printf("%d", count);
        printf(" 개");

        printf("\n");
        if (mon != 0) {
            printf("\n\n");
            printf("%d", mon);
            printf("원은 자판기가 먹었습니다ㅠ");
        }
    }
    else {
        printf("\n구매한 상품의 총 가격이 자판기에 입력한 돈보다 높습니다.");
    }
}

int hw_l3() {
    char ch;
    printf("알파벳 하나를 입력하세요 : ");
    scanf("%c", &ch);
    ch -= 255;
    printf("결과 : ");
    printf("%c", ch);
}

int main() {
    //hw_l1();
    //hw_l2();
    //hw_l3();
}
