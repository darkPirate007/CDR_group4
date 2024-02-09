#include<header.h>

extern int n;

void customerBillingFile(CUSTOMER *csr)
{
	char msisdn[20];
	FILE *fp;
	fp = fopen("/home2/user42/sprint/CDRGroup4/input_data/CB.txt", "a+");
	if (fp == NULL)
	{
		printf("\n\n Please try later\n\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("\n\nEnter MSISDN number:\n");
		scanf("%s", msisdn);
		int i;
		int flag = 0;
		char msg[MAX_LENGTH];
		char temp[MAX_LENGTH]; // char temp[mx] = 0;
		for (i = 0; i < n; i++)
		{
			if (strcmp(csr[i].msisdn, msisdn) == 0)
			{
				memset(temp, 0, MAX_LENGTH);
				sprintf(temp, "\nCustomer ID: %s ( %s )", csr[i].msisdn, csr[i].opBrand);
				strcpy(msg, temp);
				if (atoi(csr[i].opMMC) == atoi(csr[i].thirdPartyOpBrand))
				{

					memset(temp, 0, MAX_LENGTH);
					sprintf(temp, "\n\t* Services within the mobile operator *");
					strcat(msg, temp);
					if (strcmp(csr[i].callType, "MTC") == 0 || strcmp(csr[i].callType, "MOC") == 0)
					{
						if (strcmp(csr[i].callType, "MTC") == 0)

						{

							memset(temp, 0, MAX_LENGTH);
							sprintf(temp, "\n\tIncoming voice call durations: %s", csr[i].duration);
							strcat(msg, temp);
							strcat(msg, "\n\tOutgoing voice call durations: 0");
							strcat(msg, "\n\tIncoming SMS messages: 0");
							strcat(msg, "\n\tOutgoing SMS messages: 0 ");
						}
						if (strcmp(csr[i].callType, "MOC") == 0)
						{
							strcat(msg, "\n\tIncoming voice call durations: 0");
							memset(temp, 0, MAX_LENGTH);
							sprintf(temp, "\n\tOutgoing voice call durations: %s", csr[i].duration);
							strcat(msg, temp);
							strcat(msg, "\n\tIncoming SMS messages: 0");
							strcat(msg, "\n\tOutgoing SMS messages: 0 ");
						}
					}
					if (strcmp(csr[i].callType, "SMS-MT") == 0 || strcmp(csr[i].callType, "SMS-MO") == 0)
					{
						if (strcmp(csr[i].callType, "SMS-MT") == 0)
						{
							strcat(msg, "\n\tIncoming voice call durations: 0");
							strcat(msg, "\n\tOutgoing voice call durations: 0");
							strcat(msg, "\n\tIncoming SMS messages: 1");
							strcat(msg, "\n\tOutgoing SMS messages: 0 ");
						}
						if (strcmp(csr[i].callType, "SMS-MO") == 0)
						{
							strcat(msg, "\n\tIncoming voice call durations: 0");
							strcat(msg, "\n\tOutgoing voice call durations: 0");
							strcat(msg, "\n\tIncoming SMS messages: 0");
							strcat(msg, "\n\tOutgoing SMS messages: 1 ");
						}
					}

					strcat(msg, "\n\n* Services outside the mobile operator *");
					strcat(msg, "\n\tIncoming voice call durations: 0");
					strcat(msg, "\n\tOutgoing voice call durations: 0");
					strcat(msg, "\n\tIncoming SMS messages: 0");
					strcat(msg, "\n\tOutgoing SMS messages: 0");
				}
				else

				{
					strcat(msg, "\n\n * Services within the mobile operator *");
					strcat(msg, "\n\tIncoming voice call durations: 0");
					strcat(msg, "\n\tOutgoing voice call durations: 0");
					strcat(msg, "\n\tIncoming SMS messages: 0");
					strcat(msg, "\n\tOutgoing SMS messages: 0 ");

					strcat(msg, "\n\n * Services outsisde the mobile operator *");

					if (strcmp(csr[i].callType, "MTC") == 0 || strcmp(csr[i].callType, "MOC") == 0)
					{
						if (strcmp(csr[i].callType, "MTC") == 0)
						{
							memset(temp, 0, MAX_LENGTH);
							sprintf(temp, "\n\tIncoming voice call durations: %s", csr[i].duration);
							strcat(msg, temp);
							strcat(msg, "\n\tOutgoing voice call durations: 0");
							strcat(msg, "\n\tIncoming SMS messages: 0");
							strcat(msg, "\n\tOutgoing SMS messages: 0 ");
						}
						if (strcmp(csr[i].callType, "MOC") == 0)
						{
							strcat(msg, "\n\tIncoming voice call durations: 0");
							memset(temp, 0, MAX_LENGTH);
							sprintf(temp, "\n\tOutgoing voice call durations: %s", csr[i].duration);
							strcat(msg, temp);
							printf("\n\tIncoming SMS messages: 0");
							printf("\n\tOutgoing SMS messages: 0 ");
						}
					}
					if (strcmp(csr[i].callType, "SMS-MT") == 0 || strcmp(csr[i].callType, "SMS-MO") == 0)
					{
						if (strcmp(csr[i].callType, "SMS-MT") == 0)
						{
							strcat(msg, "\n\tIncoming voice call durations: 0");
							strcat(msg, "\n\tOutgoing voice call durations: 0");
							strcat(msg, "\n\tIncoming SMS messages: 1");
							strcat(msg, "\n\tOutgoing SMS messages: 0 ");
						}
						if (strcmp(csr[i].callType, "SMS-MO") == 0)
						{
							strcat(msg, "\n\tIncoming voice call durations: 0");
							strcat(msg, "\n\tOutgoing voice call durations: 0");
							strcat(msg, "\n\tIncoming SMS messages: 0");
							strcat(msg, "\n\tOutgoing SMS messages: 1 ");
						}
					}
				}
				if (strcmp(csr[i].callType, "GPRS") == 0)
				{
					strcat(msg, "\n\tIncoming voice call durations: 0");
					strcat(msg, "\n\tOutgoing voice call durations: 0");
					strcat(msg, "\n\tIncoming SMS messages: 0");
					strcat(msg, "\n\tOutgoing SMS messages: 0 ");
				}

				strcat(msg, "\n\t* Internet use *");
				memset(temp, 0, MAX_LENGTH);
				sprintf(temp, "\n\tMB downloaded: %s | MB uploaded: %s", csr[i].download, csr[i].upload);
				strcat(msg, temp);
				fprintf(fp, "%s\n\n", msg);
				printf("\n\n%s\n\n", msg);

				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("\n\nCustomer not found\n\n");
		}
	}
}
