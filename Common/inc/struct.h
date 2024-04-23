#ifndef STRUCT_H
#define STRUCT_H

#define MAX_CLIENT_COUNT 10
#define BUFFER_SIZE 256

// Holds information about each client
typedef struct ClientInfo
{
    int clientSocket;
    char clientId[MAX_CLIENT_COUNT];
    char clientAddress[BUFFER_SIZE];
};

// Holds overall client information
typedef struct MasterList
{
    int numOfClients;
    ClientInfo clientElements[MAX_CLIENT_COUNT];
} MasterList;

#endif