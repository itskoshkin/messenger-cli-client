#include "AuthService.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

/**
 * TODO FIXME
 * @param clientSocket
 * @return nothing
 */
bool doAuth(SOCKET *clientSocket) {
    printf("do you want to signup or to signin?");
    char *choice;
    do {
        scanf("%s", choice);
    } while (strcmp(choice, "signip") || strcmp(choice, "signin"));

    printf("Provide your login\n");
    char *login;
    scanf("%s", login);
    printf("Provide your password\n");
    char *password;
    scanf("%s", password);


    return false;
}