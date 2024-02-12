#include<header.h>

extern int clientSocket;
char serverMessage[1024]; // Adjust the size as needed
char serverLargeMessage[2048];

void signUp()
{
    char user_name[MAX_LENGTH];
    char password[MAX_LENGTH];
    char re_password[MAX_LENGTH];

    // Get user input
    printf("\n\n*****SIGNUP*****\n");
    printf("\nEnter user ID : ");
    scanf("%s", user_name);
    printf("\nEnter the password : ");
    scanf("%s", password);
    printf("\nRe-enter the password : ");
    scanf("%s", re_password);

    // Send user input to the server
    if (send(clientSocket, user_name, sizeof(user_name), 0) == -1)
    {
        perror("Error sending user name to server");
        exit(EXIT_FAILURE);
    }

    if (send(clientSocket, password, sizeof(password), 0) == -1)
    {
        perror("Error sending password to server");
        exit(EXIT_FAILURE);
    }

    if (send(clientSocket, re_password, sizeof(re_password), 0) == -1)
    {
        perror("Error sending re-entered password to server");
        exit(EXIT_FAILURE);
    }

    // Receive server message and print it
    if (recv(clientSocket, serverMessage, sizeof(serverMessage), 0) == -1)
    {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", serverMessage);
    sleep(3);
}

void logIn()
{
    char user_name[MAX_LENGTH];
    char password[MAX_LENGTH];
    strcpy(serverMessage, " "); // make the string empty

    // Get user input
    printf("\n\n******LOGIN******\n\n");
    printf("\nEnter user ID : ");
    scanf("%s", user_name);
    printf("\nEnter the password : ");
    scanf("%s", password);

    // Send user input to the server
    if (send(clientSocket, user_name, sizeof(user_name), 0) == -1)
    {
        perror("Error sending user name to server");
        exit(EXIT_FAILURE);
    }

    if (send(clientSocket, password, sizeof(password), 0) == -1)
    {
        perror("Error sending password to server");
        exit(EXIT_FAILURE);
    }

    // Receive server message and print it
    if (recv(clientSocket, serverMessage, sizeof(serverMessage), 0) == -1)
    {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", serverMessage);
    sleep(3);
    if (strcmp(serverMessage, "\n\nLogin Successful!\n\n") == 0)
    {
        processMenu();
    }
}
