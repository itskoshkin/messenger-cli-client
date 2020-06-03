/**
 * @authors Stanislav Stoianov, Sergey Boryaev
 */

#include "AuthService.h"
#include "TimeService.h"
#include "UserEntety.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    char message[1024];

    if (strstr(choice, "signup")) {
        sprintf(message, "%d:%s:%s%c", 1, login, password, '\0');
    } else {
        sprintf(message, "%d:%s:%s%c", 0, login, password, '\0');
    }

    int ret = send(*clientSocket, message, sizeof(message), 0);

    if (ret == SOCKET_ERROR) {
        printf("[%s] ERROR: Error sending data to server\n", getCurrentTime());
        exit(EXIT_FAILURE);
    }

    char receive[1024];

    ret = recv(*clientSocket, receive, 1024, 0);

    if (ret == SOCKET_ERROR) {
        printf("[%s] ERROR: Error receive data from server\n", getCurrentTime());
        exit(EXIT_FAILURE);
    }

    if (receive[0] == '1') {
        printf("[%s] INFO: Connected to server was successful\n", getCurrentTime());
        //FIXME
        setName(login);
        return true;
    } else {
        printf("[%s] INFO: Login or password isn't match or already occupied, please try again\n", getCurrentTime());
        return false;
    }
}