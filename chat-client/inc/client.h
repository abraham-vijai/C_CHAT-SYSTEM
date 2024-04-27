#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <netdb.h>

#define CLIENT_LOG_FP "./chat-client/tmp/client.log"
#define INIT_MESSAGE "==================== CLIENT STARTED ====================="
#define SHM_KEY 16535
#define ERROR -1
#define PORT 5000

#endif