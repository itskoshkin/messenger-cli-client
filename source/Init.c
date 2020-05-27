#include <winsock.h>
#include <stdio.h>
#include "Services/TimeService.h"
#include "Services/MessageService.h"
#include "Services/ConnectService.h"


int main() {
    WSADATA wsd;
    if (WSAStartup(MAKEWORD(1, 1), &wsd) != 0) {
        printf("[%s] Can't connect to socket lib", getCurrentTime());
        return 1;
    }

    SOCKET socket;
    connectToServer(socket);
    sendingMessage(socket);
    dissconnetFromServer(socket);

    return 0;
}

