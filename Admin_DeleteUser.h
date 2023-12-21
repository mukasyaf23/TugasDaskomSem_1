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

}DeleteUser;

char User10[30];

void deleteuser() {
    DeleteUser Deluser;
    FILE* deleteuserfile;
    FILE* deleteuserfile2;
    deleteuserfile = fopen("Data.bin", "rb");
    deleteuserfile2 = fopen("Datanew.bin", "wb");

    printf("enter the user you wanna delete :");
    scanf("%s", &User10);
    while (fread(&Deluser, sizeof(Deluser), 1, deleteuserfile)) {
        if (strcmp(Deluser.name, User10) != 0) {
            fwrite(&Deluser, sizeof(Deluser), 1, deleteuserfile2);
        }

    }

    fclose(deleteuserfile);
    fclose(deleteuserfile2);
    remove("Data.bin");
    rename("Datanew.bin", "Data.bin");
}


