#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char name[50];
    char passp[50];
    char type[50];
    int balance;
    int frequency;
    char laundrystatus[50];
    int gained;
}CustomerData;

typedef struct {
    char username[50];
    char Sprei;
    char Selimut;
    char SarungBantal;
    char Guling;
    char bedCoverSmall;
    char bedCoverMedium;
    char bedCoverlarge;
    char  whiteCloths;
    char Suits;
    char Shoes;
    char TotalCost;
    char WashingKillo;


}DataPackagesStatus;

void clientPackages(char username[50]) {
    int option, option3 ;
    FILE* FilePackages;
    DataPackagesStatus reading1;
    FilePackages = fopen("DataBaju.bin", "rb");
    while (fread(&reading1, sizeof(reading1), 1, FilePackages)) {
        if (strcmp(reading1.username, username) == 0) {
            printf("================== CUCI KILOAN ==================\n");
            printf("[1]. Regular => 2 Days => Rp.6000/Kg\n[2]. Express => 1 Day => Rp.8000/Kg\n");
            printf("=================== HOUSEHOLD ===================\n");

            printf("[3]. Sprei/Selimut/Sarung Bantal & Guling => Rp.15.000 =\n[4]. Bed Cover Kecil => Rp.10.000\n");
            printf("[5]. Bed Cover Sedang => Rp.13.000\n[6]. Bed Cover Besar => Rp.16.000\n");
            printf("==================== CLOTHES ====================\n");
            printf("[7]. White Clothes => Rp.12000\n[8]. Suit => Rp.30000\n[9]. Shoes => Rp.24000\n");
            printf("Which package you want to choose? \n\n");

            printf("1)Cuci Kiloan \n2)HouseHold \n3)Clothes \n4)Total Price\n- ");
            scanf("%d", &option);

            if (option == 1) {
                int optionCuci;
                printf("\n1)Regular\n 2)Express\n\n- ");
                scanf("%d", &optionCuci);
                if (optionCuci == 1) {
                   int CuciTotal =  reading1.WashingKillo - '0';
                    printf("%d", CuciTotal);

                }
            }
            else {

            }


        }
    }

    printf("\n THIS SHIT IS WORKING");

fclose(file);
}
