/**
 * @authors Stanislav Stoianov, Sergey Boryaev
 */

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
    char receive[1024];
    recv(socket, receive, 1024, 0);
    printf("%s", receive);
    recv(socket, receive, 1024, 0);
    printf("%s", receive);
    messageHandler(&socket);
    disconnetFromServer(&socket);
}

