/**
 * @authors Stanislav Stoianov,
 */

#include <pthread.h>
#include "MessageService.h"
#include "TimeService.h"
#include "stdbool.h"

pthread_mutex_t mutex;

void *sendThread(void *param);

_Noreturn void *recvThread(void *param);

/**
 * TODO forward username to variable
 */

char *username = "User";

/**
 * FIXME IMPORTANT test functions
 * @param clientSocket
 */

void messageHandler(SOCKET *clientSocket) {
    pthread_t send_thread_id;
    pthread_t recv_thread_id;

    pthread_create(&send_thread_id, NULL, sendThread, (void *) &clientSocket);
    pthread_detach(send_thread_id);

    pthread_create(&recv_thread_id, NULL, recvThread, (void *) &clientSocket);
    pthread_join(recv_thread_id, NULL);

    pthread_exit(NULL);
}

_Noreturn void *sendThread(void *param) {
    SOCKET clientSocket = (SOCKET) param;
    char message[1024];
    char text[992];
    while (true) {
        printf(">: ");
        scanf("%s", text);
        sprintf(message, "%s: %s", username, text);
        if (send(clientSocket, message, 1024, 0) == SOCKET_ERROR) {
            printf("Can't send message\n");
            closesocket(clientSocket);
        }
    }
}

_Noreturn void *recvThread(void *param) {
    SOCKET clientSocket = (SOCKET) param;
    char receive[1024];
    while (1) {
        recv(clientSocket, receive, 1024, 0);
        pthread_mutex_lock(&mutex);
        printf("%s", receive);
        pthread_mutex_unlock(&mutex);
    }
}