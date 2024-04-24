#include "../inc/client.h"
#include "../../Common/inc/struct.h"
#include "../../Common/src/logger.c"

int initSharedMemory(MasterList **masterList);

int main()
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