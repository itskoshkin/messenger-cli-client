#include <winsock2.h>
#include "stdbool.h"
#include "MessageService.h"
#include "ConnectService.h"
#include "AuthService.h"
#include "TimeService.h"

void run() {
    SOCKET socket;
    connectToServer(&socket);
    bool isAuthenticated = false;
    printf("[%s] INFO: Connection to the server was successful\n", getCurrentTime());
    do {
        isAuthenticated = doAuth(&socket);
    } while (!isAuthenticated);
    messageHandler(&socket);
    disconnetFromServer(&socket);
}

