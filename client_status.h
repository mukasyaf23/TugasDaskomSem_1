#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {
    char name[50];
    char passp[50];
    char type[50];
    int balance;
    int frequency;
    char laundrystatus[50];
    int gained;
}CustomerStatus;



void checkLaundryStatus(const char* username) {
    FILE* file = fopen("Data.bin", "rb");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    CustomerStatus status;

    while (fread(&status, sizeof(status), 1, file) ) {
        if (strcmp(status.name, username) == 0) {
            printf("Your laundry status: %s\n", status.laundrystatus);
            fclose(file);
            return;
        }
    }

    printf("No laundry status found for your account.\n");
    fclose(file);
}

