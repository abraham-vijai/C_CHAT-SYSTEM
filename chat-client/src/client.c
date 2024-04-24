#include "../inc/client.h"
#include "../../Common/inc/struct.h"

int main()
{
    MasterList *masterList;

    // Initialize log file
    logInit(CLIENT_LOG_FP);
    logEvent(INIT_MESSAGE);
    return 0;
}