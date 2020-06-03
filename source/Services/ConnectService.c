/**
 * @authors Stanislav Stoianov
 */

#include "ConnectService.h"
#include "TimeService.h"

#define PORT 8080

void connectToServer(SOCKET *clientSocket) {

    *clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);

    if (*clientSocket == SOCKET_ERROR) {
        printf("[%s] ERROR: Error create socket\n", getCurrentTime());
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverSockaddr_in;
    serverSockaddr_in.sin_family = AF_INET;
    serverSockaddr_in.sin_port = htons(PORT);
    serverSockaddr_in.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    if (connect(*clientSocket, (struct sockaddr *) &serverSockaddr_in, sizeof(serverSockaddr_in)) == SOCKET_ERROR) {
        printf("[%s] ERROR: Can't connect to server\n", getCurrentTime());
        closesocket(*clientSocket);
        exit(EXIT_FAILURE);
    }

}

void disconnetFromServer(const SOCKET *clientSocket) {
    closesocket(*clientSocket);
}


