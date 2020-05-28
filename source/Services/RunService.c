#include <winsock2.h>
#include "stdbool.h"
#include "MessageService.h"
#include "ConnectService.h"
#include "AuthService.h"

void run() {
    SOCKET socket;
    connectToServer(&socket);
    bool isAuthenticated = false;
    do {
        isAuthenticated = doAuth(&socket);
    } while (isAuthenticated);
    sendingMessage(&socket);
    disconnetFromServer(&socket);
}

