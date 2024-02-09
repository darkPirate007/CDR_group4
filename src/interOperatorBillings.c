#include<header.h>
extern int n;

void interOperatorBillingFile(CUSTOMER *csr)
{
	int i;
	int flag = 0;

	long int incomingcall = 0, outgoingcall = 0, incomingsms = 0, outgoingsms = 0, downloaded = 0, uploaded = 0;

	char op_number[20];
	char opname[MAX_LENGTH] = {0};

	char msg[2048] = {0};
	char temp[MAX_LENGTH];
	FILE *fp;
	fp = fopen("/home2/user42/sprint/CDRGroup4/input_data/IOSB.txt", "w");
	if (fp == NULL)
	{
		printf("\n\n Please Try Later\n\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("\n\nEnter the operator MMC/MNC number:\n");
		scanf("%s", op_number);

		for (i = 0; i < n; i++)
		{

			if (strcmp(op_number, csr[i].opMMC) == 0)
			{
				flag = 1;

					if (strcmp(csr[i].callType, "MOC") == 0)
					{
						outgoingcall += atol(csr[i].duration);
					}
					else if (strcmp(csr[i].callType, "MTC") == 0)
					{
						incomingcall += atol(csr[i].duration);
					}
					else if (strcmp(csr[i].callType, "SMS-MO") == 0)
					{
						outgoingsms += 1;
					}
					else if (strcmp(csr[i].callType, "SMS-MT") == 0)
					{
						incomingsms += 1;
					}
					else if (strcmp(csr[i].callType, "GPRS") == 0)
					{
						downloaded += atol(csr[i].download);
						uploaded += atol(csr[i].upload);
					}
					strcpy(opname, csr[i].opBrand);
			}
		}
	}
	if(flag==0){
		printf("\nOperator not found!\n");
	}
	else
	{

		strcpy(msg, "\n# Operator Data Base: \n");
		memset(temp, 0, MAX_LENGTH);
		
			sprintf(temp, "\nOperator Brand : %s ( %s )", opname, op_number);
			strcat(msg, temp);
			memset(temp, 0, MAX_LENGTH);
			sprintf(temp, "\nIncoming Voice Call Durations: %ld", incomingcall);
			strcat(msg, temp);
			memset(temp, 0, MAX_LENGTH);
			sprintf(temp, "\nOutgoing Voice Call Durations: %ld", outgoingcall);
			strcat(msg, temp);
			memset(temp, 0, MAX_LENGTH);
			sprintf(temp, "\nIncoming SMS Messages: %ld", incomingsms);
			strcat(msg, temp);
			memset(temp, 0, MAX_LENGTH);
			sprintf(temp, "\nOutgoing SMS Messages: %ld", outgoingsms);
			strcat(msg, temp);
			memset(temp, 0, MAX_LENGTH);
			sprintf(temp, "\nMB Downloaded: %ld | MB Uploaded: %ld", downloaded, uploaded);
			strcat(msg, temp);
			strcat(msg, "\n\n");
			memset(temp, 0, MAX_LENGTH);
			fprintf(fp, "%s\n\n", msg);
			printf("\n\n%s\n\n", msg);
		}
		fclose(fp);
}

