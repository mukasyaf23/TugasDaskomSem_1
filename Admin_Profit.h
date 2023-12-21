#include <stdio.h>
typedef struct
{
    char name[50];
    char passp[50];
    char type[50];
    int balance;
    int frequency;
    char laundrystatus[50];
    int gained;
}AdminProfit;

int Gains;
void BuinessProfit() {
    AdminProfit theprofit;
    FILE* seetheprofit;
    float profit, userprofit;
    seetheprofit = fopen("Data.bin", "rb");

    while (fread(&theprofit, sizeof(theprofit), 1, seetheprofit)) {
        Gains = Gains + theprofit.gained;
    }

    printf("The gains is %d", Gains);




}
