#include <header.h>
void logIn()
{
	char userName[MAX_LENGTH];
	char password[MAX_LENGTH];
	char existUsername[MAX_LENGTH];
	char existPassword[MAX_LENGTH];
	int flag = 0;

	FILE *fp = NULL;
	fp = fopen("/home2/user42/sprint/CDRGroup4/input_data/userCred.txt", "r");

	if(fp == NULL)
	{
		printf("\nPlease try again!\n");
		exit(EXIT_FAILURE);
	}

	printf("\n\t!!!!!  LOGIN  !!!!!\n");
	printf("\nEnter username : ");
	scanf("%s", userName);
	printf("\nEnter the password : ");
        scanf("%s", password);
	
	while(fscanf(fp,"%s %s\n", existUsername,existPassword)== 2)
	{
		if(strcmp(userName,existUsername) == 0)
		{
		  if(strcmp(password,existPassword) == 0)	
		  { 
			printf("\nLogIn Successful!\n");
			flag =1;
			processMenu();
			printf("\nLogout Successful\n");
			sleep(2);
			break;
		  } 
		
		}
	}
		if(flag == 0)
		{
			printf("\nAuthentication Failed!\n");
			sleep(2);
			
		}

	
	fclose(fp);
}


