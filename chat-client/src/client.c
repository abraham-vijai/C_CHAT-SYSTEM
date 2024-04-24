#include "../inc/client.h"
#include "../../Common/inc/struct.h"
#include "../../Common/src/logger.c"

int initSharedMemory(MasterList **masterList);

int main(int argc, char *argv[])
{
    MasterList *masterList;

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
        logEvent("ERROR: Cannot get shared memory block");
        return ERROR;
    }

    // Attach to shared memory block
    *masterList = (MasterList*) shmat(shmID, NULL, 0);
    if((*masterList) == NULL)
    {
        logEvent("ERROR: Cannot get shaerd memory address");
        return ERROR;
    }

    return 0;
}