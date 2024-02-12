#include <header.h>

extern int clientSocket; // Declare clientSocket as a global variable
extern int serverSocket;
char message[MAX_LENGTH];

void menu()
{

    int choice;
    while (1)
    {
        // Receive choice from the client
        if (recv(clientSocket, &choice, sizeof(choice), 0) == -1)
        {
            perror("Error receiving choice from client");
            exit(EXIT_FAILURE);
        }
        // recv(clientSocket, &choice, sizeof(choice), 0);
        switch (choice)
        {
        case 1:
            signUp();
            break;
        case 2:
            logIn();
            break;
        case 3:
            printf("\n\n\tThank you for using our application!!!\n");
            printf("\n\t\t********\n");

            close(clientSocket);
            close(serverSocket);
            exit(0);
            break;
        default:
            printf("\n\n\tEnter valid input!\n\n");
            break;
        }
    }

}

int processMenu()
{

    int ch;
    CUSTOMER *csr = NULL;
    strcpy(message," ");
    while (1)
    {

        if (recv(clientSocket, &ch, sizeof(ch), 0) == -1)
        {
            perror("Error receiving choice from client");
            exit(EXIT_FAILURE);
        }

        switch (ch)
        {
        case 1:
            if (csr == NULL)
            {
                CUSTOMER *temp = processCDR();
                csr = temp;
                if (csr == NULL)
                {
                    strcpy(message, "\n\nProcess Failed!\n");
                    send(clientSocket, message, sizeof(message), 0);

                    printf("\n\nProcess Failed!\n");
                }
                else
                {
                    strcpy(message, "\n\nProcessed the CDR file!\n");
                    send(clientSocket, message, sizeof(message), 0);

                    printf("\n\nProcessed the CDR file!\n");
                }
            }
            else
            {
                strcpy(message, "\n\nFile Already Processed!");
                send(clientSocket, message, sizeof(message), 0);

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
            break;
        }
    }
    return EXIT_SUCCESS;
}

void billingMenu(CUSTOMER *csr)
{
    int ch;
    strcpy(message, " ");
    if (recv(clientSocket, &ch, sizeof(ch), 0) == -1)
    {
        perror("Error receiving choice from client");
        exit(EXIT_FAILURE);
    }

    switch (ch)
    {
    case 1:
        customerBillingFile(csr);
        break;
    case 2:
        interOperatorBillingFile(csr);
        break;
    default:
        printf("Enter valid choice!");
        break;
    }
}

