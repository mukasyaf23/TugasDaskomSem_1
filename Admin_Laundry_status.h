#include<stdio.h>
#include<string.h>
typedef struct
{
    char name[50];
    char passp[50];
    char type[50];
    int balance;
    int frequency;
    char laundrystatus[50];
        int gained;
 
}ClientUser1;

char SoonUserRenamedLaundryState[50];
char newClientLaundryState[50];


void DisplayUser() {
    ClientUser1 readingClientsuser;
    int i = 0;

    FILE* readingLaundryFile;
    readingLaundryFile = fopen("Data.bin", "rb");

    while (fread(&readingClientsuser, sizeof(readingClientsuser), 1, readingLaundryFile)) {
        if (strcmp(readingClientsuser.type, "Admin") != 0) {
            i++;
            printf("%d) %s\n", i, readingClientsuser.name);
        }
    }
    fclose(readingLaundryFile);

}
void EditUserLaunStatus() {

    ClientUser1 readingClientsuser;
    FILE* readingLaundryFile;
    readingLaundryFile = fopen("Data.bin", "rb");
    FILE* WritingLaundryFile;
    WritingLaundryFile = fopen("NewData.bin", "wb");

    int i = 0;
    printf("\nPls enter the user's you want to edit?\n\n");
    scanf("%s", &SoonUserRenamedLaundryState);

    printf("\nEnter the new laundry status");
    scanf("%s", &newClientLaundryState);

    while (fread(&readingClientsuser, sizeof(readingClientsuser), 1, readingLaundryFile) ){
        if ( strcmp (readingClientsuser.name, SoonUserRenamedLaundryState) == 0) {
            strcpy(readingClientsuser.laundrystatus, newClientLaundryState);
        }
    fwrite(&readingClientsuser, sizeof(readingClientsuser), 1, WritingLaundryFile);
    }
    fclose(readingLaundryFile);
    fclose(WritingLaundryFile);
    remove("Data.bin");
    rename("NewData.bin", "Data.bin");
}

void laundry() {
    printf("List of all the user\n\n");
    DisplayUser();
    EditUserLaunStatus();
}