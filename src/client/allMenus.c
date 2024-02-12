#include<header.h>

extern int clientSocket;
extern char serverMessage[1024];
extern char serverLargeMessage[2048];

void menu()
{
    int choice;
    while (1)
    {
        system("clear");
        printf("\n\n\n\t\t Welcome to Call Data Record Application!!!\n\n");
        printf("\n\n==============================================================================\n\n");
        printf("1. Signup\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        // Send choice to the server
        if (send(clientSocket, &choice, sizeof(choice), 0) == -1)
        {
            perror("Error sending choice to server");
            exit(EXIT_FAILURE);
        }

        switch (choice)
        {
        case 1:
        {
            signUp();
            break;
        }
        case 2:
        {
            logIn();
            break;
        }
        case 3:
            printf("\n\n\tThank you for using our application!!!\n");
            printf("\n\t\t********\n");

            close(clientSocket);
            exit(0);

        default:
            printf("\n\n\tInvalid Choice!\n\n");
            break;
        }
    }
}

int processMenu()
{
    int ch;
    strcpy(serverMessage, " ");
    // CUSTOMER *csr = NULL;
    while (1)
    {
        printf("\n\n1. Process CDR File");
        printf("\n\n2. Billing");
        printf("\n\n3. Logout");
        printf("\n\nChoice: ");
        scanf("%d", &ch);

        // Send choice to the server
        if (send(clientSocket, &ch, sizeof(ch), 0) == -1)
        {
            perror("Error sending choice to server");
            exit(EXIT_FAILURE);
        }

        switch (ch)
        {
        case 1:
            // Receive server message and print it
            if (recv(clientSocket, serverMessage, sizeof(serverMessage), 0) == -1)
            {
                perror("Error receiving message from server");
                exit(EXIT_FAILURE);
            }

            printf("%s", serverMessage);
            break;
        case 2:
            billingMenuClient();
            break;
        case 3:
            // free(csr);
            return EXIT_SUCCESS;
        default:
            printf("\n\nEnter Valid Choice");
            break;
        }
    }
    return EXIT_SUCCESS;
}

void billingMenuClient()
{
    int ch;
    strcpy(serverMessage, " ");

    printf("\n\n 1. Customer Billing \n\n 2. Interoperator Billing\n\n");
    printf("\n\nChoice: ");
    scanf("%d", &ch);
    // Send choice to the server
    if (send(clientSocket, &ch, sizeof(ch), 0) == -1)
    {
        perror("Error sending choice to server");
        exit(EXIT_FAILURE);
    }
    switch (ch)
    {
    case 1:
        customerBillingClient();
        break;
    case 2:
        interOperatorBillingClient();
        break;
    default:
        printf("Enter Valid Choice!");
        break;
    }
}
