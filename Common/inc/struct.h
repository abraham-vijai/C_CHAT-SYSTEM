#ifndef STRUCT_H
#define STRUCT_H

#define MAX_CLIENT_COUNT 10

typedef struct ClientInfo
{

} ClientInfo;


typedef struct MasterList
{
    int numOfClients;
    ClientInfo clientElements[MAX_CLIENT_COUNT];
} MasterList;



#endif