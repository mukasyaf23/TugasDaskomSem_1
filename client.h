#include <stdio.h>
#include <string.h>
#include "client_sending.h"
#include "client_status.h"
#include "client_packages.h"
typedef struct {
    char name[50];
    char passp[50];
    char type[50];
    int balance;
    int frequency;
    char laundrystatus[50];
    int gained;

} ClientUser;


ClientUser BalanceSystem;
int topup;
int balance;

void balance_laundry(char username[50]) {
    int option1;
    FILE* file_client;
    FILE* file_client_baru;

    file_client = fopen("Data.bin", "rb");
    file_client_baru = fopen("database_user_new.bin", "wb");

    printf("\n1) Check Balance\n2) Top Up Balance\n");
    printf("\nChoose Option: ");
    scanf("%d", &option1);

    switch (option1) {
    case 1:
        while (fread(&BalanceSystem, sizeof(BalanceSystem), 1, file_client)){


            if (strcmp(username, BalanceSystem.name) == 0) {
                int user_choice;
                printf("Your Balance is - %d", BalanceSystem.balance);

            }
            break;


    case 2:
        printf("Enter how much money you want to add: ");
        scanf("%f", &topup);


        if (topup > 0) {

            topup = BalanceSystem.balance + topup;
            while (fread(&BalanceSystem, sizeof(BalanceSystem),1,file_client)) {
                if (strcmp(username, BalanceSystem.name) == 0) {
                    BalanceSystem.balance = topup;
                }
                fwrite(&BalanceSystem, sizeof(BalanceSystem), 1, file_client_baru);
            }
            printf("");
            

            printf("Balance successfully updated!\n");
        }
        else {
            printf("Invalid amount entered. Please enter a positive value.\n");
            break;
        }







    default:
        printf("\nInvalid option!\n");
        printf("Please try again\n");
        break;
        }

        fclose(file_client);
        fclose(file_client_baru);
    }

}


void Client_Homepage(char username[50]) {
    int option;
    FILE* file1;
    file1 = fopen("Data.bin", "rb");

    printf("\n\n1) Balance\n2) Sending Laundry\n3) Status Laundry\n4) View Packages and Prices\n5) Exit\n\n");
    printf("Choose Option: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
        balance_laundry(username);
        break;

    case 2:
        clientSending(username);
        break;

    case 3:
        checkLaundryStatus(username);
        break;

    case 4:
        clientPackages(username);
        break;

    case 5:
        // Exit or return to menu
        break;

    default:
        printf("\nInvalid option!\n");
        printf("Please try again\n");
        break;
    }

    fclose(file1);
}