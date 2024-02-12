#include<header.h>

extern int clientSocket;
extern char serverMessage[1024]; // Adjust the size as needed
extern char serverLargeMessage[2048];

void customerBillingClient()
{
    char msisdn[20];
    printf("\n\nEnter MSISDN number:\n");
    scanf("%s", msisdn);
    if (send(clientSocket, msisdn, sizeof(msisdn), 0) == -1)
    {
        perror("Error sending choice to server");
        exit(EXIT_FAILURE);
    }

    // Receive server message and print it
    if (recv(clientSocket, serverLargeMessage, sizeof(serverLargeMessage), 0) == -1)
    {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", serverLargeMessage);
    sleep(3);
}

void interOperatorBillingClient()
{

    char op_number[20];
    strcpy(serverLargeMessage, " ");

    printf("\n\nEnter the operator MMC/MNC number:\n");
    scanf("%s", op_number);
    if (send(clientSocket, op_number, sizeof(op_number), 0) == -1)
    {
        perror("Error sending op number to server");
        exit(EXIT_FAILURE);
    }

    // Receive server message and print it
    if (recv(clientSocket, serverLargeMessage, sizeof(serverLargeMessage), 0) == -1)
    {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", serverLargeMessage);
    sleep(3);
}
