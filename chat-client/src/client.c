#include "../inc/client.h"
#include "../../Common/inc/struct.h"
#include "../../Common/src/logger.c"

int initSharedMemory(MasterList **masterList);
void parseArguments(int argc, char *argv[], char args[2][BUFFER_SIZE]);
int connectToServer(MasterList* masterList, char args[2][BUFFER_SIZE]);

int main(int argc, char *argv[])
{
    MasterList *masterList;
    char args[2][BUFFER_SIZE];

    // Initialize log file
    logInit(CLIENT_LOG_FP);
    logEvent(INIT_MESSAGE);
    
    logEvent("Intializing shared memory ...");
    if(initSharedMemory(&masterList) == ERROR)
    {
        return ERROR;
    }

    // Checking the number of arguments
    if(argc != 3)
    {
        printf ("chat-client -user<userID> -server<server name>\n");
        return 0;
    }

    // Parse the command line arguments
    parseArguments(argc, argv, args);

    return 0;
}

int initSharedMemory(MasterList **masterList)
{
    int shmID;
    key_t shmKey;

    shmKey = ftok("a", SHM_KEY);

    // Attempt to get shared memory block
    while((shmID = shmget(shmKey, sizeof(MasterList), 0) == ERROR))
    {
        logError("Cannot get shared memory block");
        return ERROR;
    }

    // Attach to shared memory block
    *masterList = (MasterList*) shmat(shmID, NULL, 0);
    if((*masterList) == NULL)
    {
        logError("ERROR: Cannot get shaerd memory address");
        return ERROR;
    }

    return 0;
}

void parseArguments(int argc, char *argv[], char args[2][BUFFER_SIZE])
{
    // Loop through the command line arguments
    for (int i = 0; i < argc; i++)
    {
        // Check if the argument starts with '-user'
        if(strncmp(argv[i],"-user",strlen("-user")) == 0)
        {
            // Extract the user id
            strncpy(args[0], argv[i] + strlen("-user"), BUFFER_SIZE);
            args[0][strlen(args[0])] = '\0';
        }
        // Check if the argument starts with "-server"
        else if (strncmp(argv[i], "-server", strlen("-server")) == 0)
        {
            // Extract the server name
            strncpy(args[1], argv[i] + strlen("-server"), BUFFER_SIZE);
            args[1][strlen(args[1])] = '\0'; 
        } 
    }
}

int connectToServer(MasterList* masterList, char args[2][BUFFER_SIZE])
{
    int serverSocket;
    struct hostent* hostStruct;
    struct sockaddr_in serverStruct;
    
    // Getting host info
    logEvent("Getting host info with IP address ...");
    if((hostStruct = gethostbyname(args[1]))== NULL) 
    {
        logError("Cannot get host");
        return ERROR;
    }

    // Initialize the server struct
    logEvent("Initializing server struct");
    memset(&serverStruct, 0, sizeof(serverStruct)); // Set size to 0 
    memcpy(&serverStruct.sin_addr, 
    hostStruct->h_addr, hostStruct->h_length);      // Set server address 
    serverStruct.sin_family = AF_INET;              // Set address type
    serverStruct.sin_port = htons(PORT);            // Set port

}