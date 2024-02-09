#include<header.h>

int processMenu()
{
	int ch;
	CUSTOMER *csr = NULL;
	while(1)
	{
	printf("\n\n1. Process CDR File");
	printf("\n\n2. Billing");
	printf("\n\n3. Logout");
	printf("\n\nChoice: ");
	scanf("%d", &ch);

	switch(ch)
	{
		case 1: 
			if(csr == NULL)
			{
				CUSTOMER* temp = processCDR();
				csr = temp;
				if(csr == NULL)
				{
					printf("\n\nProcess Failed!\n");
				}
				else
				{
					printf("\n\nProcessed the CDR file!\n");

				}
			}
			else
			{
				printf("\n\nFile Already Processed!");
			}
			break;
		case 2:
			billingMenu(csr);
			break;
		case 3:
			free(csr);
			return EXIT_SUCCESS;
		default:
			printf("\n\nEnter Valid Choice");
	}
  }
  return EXIT_SUCCESS;
}

void billingMenu(CUSTOMER *csr)
{
	int ch;
	printf("\n\n 1. Customer Billing \n\n 2. Interoperator Billing\n\n");
	printf("\n\nChoice: ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:
			customerBillingFile(csr);
			break;
		case 2:
			interOperatorBillingFile(csr);
			break;
	}
}
