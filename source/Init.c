/**
 * @authors Stanislav Stoianov
 */

#include <winsock2.h>
#include <stdio.h>
#include "Services/TimeService.h"
#include "Services/RunService.h"


int main() {
    WSADATA wsd;
    if (WSAStartup(MAKEWORD(1, 1), &wsd) != 0) {
        printf("[%s] ERROR: Can't connect to socket lib\n", getCurrentTime());
        exit(EXIT_FAILURE);
    }

    run();

    return 0;
}

