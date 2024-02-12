#include<header.h>

const char *log_levels[] = {
    "", // Empty string for level 0
    "INFO",
    "WARNING",
    "ERROR",
    "FATAL"
};
int clientSocket;
int main()
{
    struct sockaddr_in serverAddr;

    // Create socket
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error creating socket");
        LOG(LOG_LEVEL_ERROR, "Error creating socket");
	exit(EXIT_FAILURE);
    }

    // Set up server address structure
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Assuming server is on the same machine
    serverAddr.sin_port = htons(PORT);

    // Connect to server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        perror("Error connecting to server");
	LOG(LOG_LEVEL_ERROR, "Error creating socket");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");
	LOG(LOG_LEVEL_INFO, "Server listening on port!");

    menu();

    return 0;
}
