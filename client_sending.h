#include <stdio.h>


typedef struct {
    char name[50];
    char passp[50];
    char type[50];
    int balance;
    int frequency;
    char laundrystatus[50];
    int gained;
}Customer;

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



}DataTobeSend;

int sendingUserLaundry(char user[50]) {
    DataTobeSend Sending;
    FILE* file23;
    file23 = fopen("DataBaju.bin", "ab");
    strcpy(Sending.username, user);
    printf("=================== HOUSEHOLD ===================\n");
    printf("[1]. Sprei ");
    scanf("%c", &Sending.Sprei); getchar();
    printf("[2]. Selimut ");
    scanf("%c", &Sending.Selimut); getchar();
    printf("[3]. SarungBantal ");
    scanf("%c", &Sending.SarungBantal); getchar();
    printf("[4]. Guling ");
    scanf("%c", &Sending.Guling); getchar();
    printf("[5]. Bed Cover Kecil: ");
    scanf("%c", &Sending.bedCoverSmall); getchar();
    printf("[6]. Bed Cover Sedang: ");
    scanf("%c", &Sending.bedCoverMedium); getchar();
    printf("[7]. Bed Cover Besar: ");
    scanf("%c", &Sending.bedCoverlarge); getchar();
    printf("==================== CLOTHES ====================\n");
    printf("[5]. White Clothes: ");
    scanf("%c", &Sending.whiteCloths); getchar();
    printf("[6]. Suit: ");
    scanf("%c", &Sending.Suits); getchar();
    printf("[7]. Shoes: ");
    scanf("%c", &Sending.Shoes); getchar();
    printf("[8]. Wash Kilos: ");
    scanf("%c", &Sending.WashingKillo); getchar();

    fwrite(& Sending, sizeof(Sending), 1, file23);
    fclose(file23);

}

int clientSending(char username[50]) {
    int num, option12;
    sendingUserLaundry(username);

    printf("1) Sending Laundry\n2) Exit\n");
    printf("Choose what you want: ");
    scanf("%i", &option12);

    switch (option12) {
    case 1:
        sendingUserLaundry(username);
        break;

    case 2:
        //

    default:
        printf("Invalid choice, Please select a valid option!\n");

    }
}
  