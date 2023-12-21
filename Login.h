#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Register.h"
#include"admin.h"
#include"client.h"

int option = 0;
typedef struct 
{
    char name[50];
    char passp[50];
    char type[50];
    int balance;
    int frequency;
    char laundrystatus[50];
    int gained;
}User;

int loginvalue;
int authenvalue = 0;
int couter = 0;
char userType[50];
char Clientname[50];

int Authentication(User user2,char username[50], char password[50]) {

    FILE* file1;
    file1 = fopen("Data.bin", "rb");

    
    while (fread(&user2, sizeof(user2), 1, file1)) {

        if (strcmp(user2.name, username) == 0 && strcmp(user2.passp,password)==0) {
            strcpy(userType,user2.type);
 
            authenvalue =1;
            break;
        }
        else {
            authenvalue = 0;
        }
        
    }
    fclose(file1);

}


int login() {
     User user,user1;
 
    printf("Enter your Username - ");
    scanf("%s", &user.name);
    printf("Enter your password - ");
    scanf("%s", &user.passp);
    Authentication(user1, user.name, user.passp);
    strcpy(Clientname, user.name);
    printf("%s", userType);
    if (authenvalue == 1) {
        if (strcasecmp(userType, "Client") == 0) {
            loginvalue = 2;
        }
        else {
            loginvalue = 1;
        }
    }
 
    else {

        loginvalue = 0;
    }
}

int start() {

    printf("====Register/Login====\n\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. quit\n\n- ");
    scanf("%d", &option);
    while (option != 3) {
        if (option == 1) {
            Registerol();
            break;
        }
        else if (option == 2) {
            login();
            if (loginvalue == 1) {
                printf("Welcome Admin");
                printf("\033[2J\033[1;1H");
                Admin_Homepage();
                break;
                
            }
            else if (loginvalue ==2){
                printf("\033[2J\033[1;1H");
                printf("Welcome dear clinet");
                Client_Homepage(Clientname); 
                break;
            }

            else {
                printf("wrong username and passsword\n\n pls try again\n\n");
            }
   
        }
        else {
            option = 3;
        }

        // login sucess for admin
    }
  
}