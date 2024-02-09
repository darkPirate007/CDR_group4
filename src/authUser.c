#include <header.h>

int authUser(char userName[], char password[])
{
	char existUsername[MAX_LENGTH];
	char existPassword[MAX_LENGTH];
	int flag = 1;
	FILE *fp;
	fp = fopen("/home2/user42/sprint/CDRGroup4/input_data/userCred.txt","r");
	if(fp == NULL)
	{
		printf("\n Please try again!!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while(fscanf(fp,"%s %s\n", existUsername,existPassword)== 2)
		{
			if(strcmp(userName,existUsername) == 0)
			{
				flag = 0;
				break;
			}
		}
        fclose(fp);
	return flag;
	}
}
