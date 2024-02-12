#include <header.h>

int clientSocket; // Declare clientSocket as a global variable
int serverSocket;
const char *log_levels[] = {
    "", // Empty string for level 0
    "INFO",
    "WARNING",
    "ERROR",
    "FATAL"
};


int main()
{

    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize = sizeof(struct sockaddr_in);

    // Create socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error creating socket");
	LOG(LOG_LEVEL_ERROR, "Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        perror("Error binding socket");
	LOG(LOG_LEVEL_ERROR, "Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1)
    {
        perror("Error listening");
	LOG(LOG_LEVEL_ERROR, "Error listening");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);
   LOG(LOG_LEVEL_INFO, "Server listening on port"); 

    // Accept a connection
    if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrSize)) == -1)
    {
	LOG(LOG_LEVEL_ERROR, "Error accepting connection");
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    printf("Connection established with client\n");
   LOG(LOG_LEVEL_INFO, "Connection established with client");

    // Handle client requests
    menu();

    // close(serverSocket);
    return 0;
}

