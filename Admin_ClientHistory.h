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
}AdminAccessClientHistory;

char ClientHistorySearname[50];
int AdminClientSearchOption1;
int ab =0;

void Frequency_InsertSorting(AdminAccessClientHistory arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i].frequency;
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j].frequency > key) {
            arr[j + 1].frequency = arr[j].frequency;
            j = j - 1;
        }
        arr[j + 1].frequency = key;
    }
    printf("Name %02s Frequencey\n");
    int ia;
    for (ia = 0; ia < ab - 1; ia++){
        printf("%s        %d\n", arr[ia].name, arr[ia].frequency);
        printf("\n");
    }
}

void allClientHistory() {
    AdminAccessClientHistory l[ab] ;
    AdminAccessClientHistory b;
    FILE* Alluserread;
    int i = 0;


    Alluserread = fopen("Data.bin", "rb");
    while (fread(&l[i], sizeof(b), 1, Alluserread)) {
        if (strcmp(l[i].type, "Admin") != 0) {

            i++;
        }
    }
    fclose(Alluserread);
    Frequency_InsertSorting(l, ab);



}
void AuserHistory() {
    AdminAccessClientHistory a;
    FILE* Auserread;
    Auserread = fopen("Data.bin", "rb");

    printf("Enter the user's name that you want to see \n\n");
    scanf("%s", &ClientHistorySearname);

    while (fread(&a, sizeof(a), 1, Auserread)) {
        if (strcmp(a.name, ClientHistorySearname) == 0) {
            printf("\n\n=== The History of %s ===", ClientHistorySearname);
            printf("\n\nFrequency - %s\nBalance - %s\nLaundry status -%s\nProfit - \n\n", a.frequency, a.balance, a.laundrystatus);
            
        }
    }


     fclose(Auserread);

}
void ClientHistory() {

    FILE* NumUser;
    AdminAccessClientHistory c;
    NumUser = fopen("Data.bin", "rb");
    while (fread(&c, sizeof(c), 1, NumUser)) {
        ab++;
    }

    printf("1) See a Client's history \n2) See all Client's histories\n\n");
    scanf("%d", &AdminClientSearchOption1);


    switch (AdminClientSearchOption1) {
    case 1:
        AuserHistory();
        break;
    case 2:
        allClientHistory();
        break;
    default:
        printf("Pls enter with the following\n");
        ClientHistory();
    }
}