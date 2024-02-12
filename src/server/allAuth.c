#include <header.h>

extern int clientSocket; // Declare clientSocket as a global variable
extern int serverSocket;
extern char message[MAX_LENGTH];

int authUser(char userName[], char password[])
{
    char existUsername[MAX_LENGTH];
    char existPassword[MAX_LENGTH];
    int flag = 1;
    FILE *fp;
    fp = fopen("/home2/user42/CDR_group4/data/userCred.txt", "r");
    if (fp == NULL)
    {
        printf("\n Please try again!!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        while (fscanf(fp, "%s %s\n", existUsername, existPassword) == 2)
        {
            if (strcmp(userName, existUsername) == 0)
            {
                flag = 0;
                break;
            }
        }
        fclose(fp);
        return flag;
    }
}

void signUp()
{
    char user_name[MAX_LENGTH];
    char password[MAX_LENGTH];
    char re_password[MAX_LENGTH];

    // Receive user input from client
    if (recv(clientSocket, user_name, sizeof(user_name), 0) == -1)
    {
        perror("Error receiving user name from client");
        exit(EXIT_FAILURE);
    }

    if (recv(clientSocket, password, sizeof(password), 0) == -1)
    {
        perror("Error receiving password from client");
        exit(EXIT_FAILURE);
    }

    if (recv(clientSocket, re_password, sizeof(re_password), 0) == -1)
    {
        perror("Error receiving re-entered password from client");
        exit(EXIT_FAILURE);
    }

    printf("\n\n*****SIGNUP*****\n");

    // Inform the client about the registration status
    char registrationStatus[200];
    int checkAuth = authUser(user_name, password);

    if (strcmp(password, re_password) == 0)
    {
        // Perform signup logic
        // Implement communication between client and server for signup logic

        if (checkAuth)
        {
            FILE *fp = fopen("/home2/user42/CDR_group4/data/userCred.txt", "a+");
            if (fp != NULL)
            {
                fprintf(fp, "%s %s\n", user_name, password);
                fclose(fp);
            }
            sprintf(registrationStatus, "\nRegistration successful\n\nLogin with your credentials!\n");
            sleep(2);
        }
        else
        {
            sprintf(registrationStatus, "User already exists!\n");
        }
    }
    else
    {
        // Implement communication between client and server for informing the client about password mismatch
        sprintf(registrationStatus, "Password mismatch\n");
    }

    if (send(clientSocket, registrationStatus, sizeof(registrationStatus), 0) == -1)
    {
        perror("Error sending registration status to client");
        exit(EXIT_FAILURE);
    }
}

void logIn()
{

    char user_name[MAX_LENGTH];
    char password[MAX_LENGTH];
    char exist_username[MAX_LENGTH];
    char exist_password[MAX_LENGTH];
    int flag = 0;

    // Receive user input from client
    if (recv(clientSocket, user_name, sizeof(user_name), 0) == -1)
    {
        perror("Error receiving user name from client");
        exit(EXIT_FAILURE);
    }

    if (recv(clientSocket, password, sizeof(password), 0) == -1)
    {
        perror("Error receiving password from client");
        exit(EXIT_FAILURE);
    }

    // Your login logic
    FILE *fp = fopen("/home2/user42/CDR_group4/data/userCred.txt", "r");

    if (fp == NULL)
    {
        printf("\n\nPlease try later!!\n\n");
        exit(EXIT_FAILURE);
    }

    printf("\n\n******LOGIN******\n\n");
    // printf("\nEnter user ID : %s\n", user_name);
    // printf("\nEnter the password : %s\n", password);

    while (fscanf(fp, "%s %s\n", exist_username, exist_password) == 2)
    {
        if (strcmp(user_name, exist_username) == 0)
        {
            if (strcmp(password, exist_password) == 0)
            {
                printf("\n\nLogin Successful\n\n");
                flag = 1;

                // Send login success message to the client
                char loginSuccessMessage[] = "\n\nLogin Successful!\n\n";
                if (send(clientSocket, loginSuccessMessage, sizeof(loginSuccessMessage), 0) == -1)
                {
                    perror("Error sending login success message to client");
                    exit(EXIT_FAILURE);
                }

                break;
            }
        }
    }

    if (flag == 0)
    {
        // Send login failure message to the client
        char loginFailureMessage[] = "\n\n Authentication Failed\n\n";
        if (send(clientSocket, loginFailureMessage, sizeof(loginFailureMessage), 0) == -1)
        {
            perror("Error sending login failure message to client");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        processMenu();
    }

    fclose(fp);
}

