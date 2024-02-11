#include <header.h>

extern int clientSocket; // Declare clientSocket as a global variable
extern int serverSocket;
extern char message[MAX_LENGTH];
int n = 0;

CUSTOMER *processCDR()
{
    FILE *fp;
    fp = fopen("/home2/user42/CDR_group4/data/data.cdr", "r");
    CUSTOMER *csr = NULL;
    char record[9][MAX_LENGTH];
    char string[MAX_LENGTH] = {0};
    int i = 0;
    strcpy(message, " ");

    if (fp == NULL)
    {
        strcpy(message, "\n\nPlease try again!\n");
        send(clientSocket, message, sizeof(message), 0);

        printf("\n\nPlease try again!");
        return NULL;
    }
    else
    {
        // read the line from .cdr file untill last character, new line or end of line
        while (fgets(string, MAX_LENGTH, fp) != NULL)
        {
            char *token = strtok(string, "|");
            while (token != NULL)
            {
                if (i == 7 && strcmp(record[3], "GPRS") == 0) // when using internet 3rdpartyMSISDN = ' '
                {
                    strcpy(record[i], " ");
                    i++;
                    continue;
                }
                strcpy(record[i], token);
                token = strtok(NULL, "|");
                i++;
            }

            i = 0;
            n++;
            csr = realloc(csr, n * sizeof(CUSTOMER));

            strcpy(csr[n - 1].msisdn, record[0]);
            strcpy(csr[n - 1].opBrand, record[1]);
            strcpy(csr[n - 1].opMMC, record[2]);
            strcpy(csr[n - 1].callType, record[3]);
            strcpy(csr[n - 1].duration, record[4]);
            strcpy(csr[n - 1].download, record[5]);
            strcpy(csr[n - 1].upload, record[6]);
            strcpy(csr[n - 1].thirdPartyMsisdn, record[7]);
            strcpy(csr[n - 1].thirdPartyOpBrand, record[8]);
        }
    }
    fclose(fp);
    return csr;
}
