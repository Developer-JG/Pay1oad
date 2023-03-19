#include <stdio.h>

int hw_l2(){
    int mon = 0, sold_mon = 0;
    int mon_type[] = {50000, 10000, 5000, 1000, 500, 100};
    int mon_type_len = sizeof(mon_type) / sizeof(mon_type[0]);
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
        for (int type = 0; type < mon_type_len; type++) {
            count = 0;
            for (int plag = 0; mon_type[type] <= mon; ++plag) {
                mon -= mon_type[type];
                count += 1;
            }
            if (mon_type[type] >= 1000) {
                printf("%d원 지폐 : %d장\n", mon_type[type], count);
            }
            else {
                printf("%d원 동전 : %d개\n", mon_type[type], count);
            }
        }
        printf("\n");
        if (mon != 0) {
            printf("%d", mon);
            printf("원은 자판기가 먹었습니다ㅠ\n");
        }
    }
    else {
        printf("\n구매한 상품의 총 가격이 자판기에 입력한 돈보다 높습니다.");
    }
}

int main() {
    hw_l2();
}
