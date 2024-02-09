#include<header.h>

 int main()
{
	menu();
	return EXIT_SUCCESS;
}

void menu()
{
	int choice;
	while(1)
	{
		system("clear");
		printf("\n\n\t-->  HELLO! Welcome to Call Data Record Application!!!  <--\n\n");
		printf("\n\n==============================================================================\n\n");
		printf("\tEnter Your Choice!\n\n");
		printf("1. Signup\n");
		printf("2. Login\n");
		printf("3. Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: signUp();
				break;
			case 2: logIn();
				break;
			case 3:
				printf("\n\n\t-->  Thank You for using our application!!!  <--\n");
				printf("\n\t\t************************************\n");
				exit(0);
				break;
			default:
				printf("\n\n\tEnter a Valid Choice!\n\n");
		}
	}
}
