#include <header.h>

extern int clientSocket; // Declare clientSocket as a global variable
extern int serverSocket;
extern char message[MAX_LENGTH];
extern int n;

void customerBillingFile(CUSTOMER *csr)
{
    char msisdn[20];
    FILE *fp;
    fp = fopen("/home2/user42/CDR_group4/data/CB.txt", "a+");
    if (fp == NULL)
    {
        printf("\n\n Please try later\n\n");
        perror("\n\n Please try later\n\n");
        close(clientSocket);
        exit(EXIT_FAILURE);
    }
    else
    {
        // printf("\n\nEnter MSISDN number:\n");
        // scanf("%s", msisdn);

        if (recv(clientSocket, msisdn, sizeof(msisdn), 0) == -1)
        {
            perror("Error receiving msisdn from client");
            exit(EXIT_FAILURE);
        }

        int i;
        int flag = 0;
        char msg[MAX_LENGTH];
        char temp[MAX_LENGTH];
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
                send(clientSocket, msg, sizeof(msg), 0);

                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            char ms[] = "\n\nCustomer not found\n\n";
            send(clientSocket, ms, sizeof(ms), 0);
        }
    }
}

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
    fp = fopen("/home2/user42/CDR_group4/data/IOSB.txt", "w");
    if (fp == NULL)
    {
        printf("\n\n Please Try Later\n\n");
        perror("\n\n Please Try Later\n\n");
        close(clientSocket);
        exit(EXIT_FAILURE);
    }
    else
    {
        // printf("\n\nEnter the operator MMC/MNC number:\n");
        // scanf("%s", op_number);
        if (recv(clientSocket, op_number, sizeof(op_number), 0) == -1)
        {
            perror("Error receiving op number from client");
            exit(EXIT_FAILURE);
        }

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
    if (flag == 0)
    {
        char ms[] = "\nOperator not found!\n";
        send(clientSocket, ms, sizeof(ms), 0);
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

        send(clientSocket, msg, sizeof(msg), 0);
    }
    fclose(fp);
}

