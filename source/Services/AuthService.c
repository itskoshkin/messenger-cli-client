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
    char choice[10];
    do {
        fgets(choice, 10, stdin);
    } while (strcmp(choice, "signup") || strcmp(choice, "signin"));
    printf("Provide your login\n");
    char login[30];
    fgets(login, 30, stdin);
    printf("Provide your password\n");
    char password[30];
    fgets(password, 30, stdin);


    return false;
}