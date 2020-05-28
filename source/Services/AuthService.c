#include "AuthService.h"
#include "TimeService.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

bool doAuth(SOCKET *clientSocket) {
    char *choice = (char *) calloc(8, sizeof(char));

    do {
        printf("Do you want to signup or to signin?\n");
        scanf("%s", choice);
    } while (strcmp(choice, "signup") && strcmp(choice, "signin"));



    printf("Provide your login (less than 32 characters)\n");
    char login[32];
    scanf("%32s", login);

    fflush(stdin);

    printf("Provide your password (less than 32 characters)\n");
    char password[32];
    scanf("%32s", password);

    char *message;

    if (strstr(choice, "signup")) {
        sprintf(message, "%d:%s:%s", 1, login, password);
    } else {
        sprintf(message, "%d:%s:%s", 0, login, password);
    }

    int ret = send(*clientSocket, message, sizeof(message), 0);

    if (ret == SOCKET_ERROR) {
        printf("[%s] ERROR: Error sending data\n", getCurrentTime());
        exit(EXIT_FAILURE);
    }

    char recieve[1];
    ret = recv(clientSocket, recieve, 1024, 0);

    //TODO parse message return true

    return false;
}