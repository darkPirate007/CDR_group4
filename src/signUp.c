#include<header.h>

void signUp()
{

	char userName[MAX_LENGTH];
	char password[MAX_LENGTH];
	char confirmPass[MAX_LENGTH];
	FILE *fp = NULL;
	fp = fopen("/home2/user42/sprint/CDRGroup4/input_data/userCred.txt", "a+");
	if(fp == NULL)
	{
		printf("\nPlease try again!!\n");
		exit(EXIT_FAILURE);
	}
	printf("\n!!!!!  SIGNUP  !!!!!\n");

	printf("\nEnter username : ");
	scanf("%s", userName);

	printf("\nEnter the password : ");
	scanf("%s", password);

	printf("\nConfirm the password : ");
	scanf("%s", confirmPass);

	int checkAuth = authUser(userName,password);   //to save value returned by authUser (0 or 1)

	if(strcmp(password,confirmPass) == 0)
	{
		if(checkAuth)
		{
			fprintf(fp, "%s %s\n", userName, password);
			printf("\nRegistration successful\n\n");
			printf("\nYou can Login with your credentials!\n");
			sleep(2);
		}
		else
		{
			printf("\nUser already exist!!\n");
			sleep(2);
		}
	}
	else
	{
		printf("Password does not matched\n");
		sleep(3);
	}
	fclose(fp);
	menu();

}
