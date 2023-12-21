#include<stdio.h>
#include"Admin_DeleteUser.h"
#include "Admin_Laundry_status.h"
#include "Admin_ClientHistory.h"
#include "Admin_Profit.h"
typedef struct {
	char NameVerif[50];
	char PassVerif[50];
	char type[50];
	int frequency;
	char laundrystatus[50];
	int gained;
}AdminUser;


int AdminOption1;
void Admin_Homepage() {

	printf("Welcome dear Admin\n\n");

	printf("1)Delete User \n2)Profit \n3)Status_laundry\n4)Top_customer \n5)Exit \n\n");
	scanf("%d", &AdminOption1);

	switch (AdminOption1)
	{
	case 1:
		deleteuser();
		break;
		
	 case 2:
		 BuinessProfit();
		break;
		
	 case 3:
		 laundry();
		 break;
		 
	 case 4:
		 ClientHistory();
		 break;
	 case 5:
		 break;
	default:
		printf("pls enter within the given output");
	}




}