/**
 * @authors Stanislav Stoianov, Daria Pavlova
 */

#include "MessageService.h"
#include "TimeService.h"
#include "stdbool.h"

#define PORT 8080

/** TODO
 * добавить авторизацию и регистрацию
 * добавить обработку нажатия клавиши для выхода из чата
 */

char *username = "User";

void sendingMessage(SOCKET clientSocket) {

    char message[1024];

    /*
    printf("Enter your username: ");
    scanf("&s\n", username);
    */

    while (true) {
        char text[512];
        scanf("%s", text);

        sprintf(message, "[%s] %s: %s", getCurrentTime(), username, text);
        int ret = send(clientSocket, message, strlen(message), 0);

        if (ret == SOCKET_ERROR) {
            printf("Can't send message\n");
            closesocket(clientSocket);
            return;
        }

        printf("[%s] Sent: %s, includes %d bytes\n", getCurrentTime(), message, ret);
        ret = SOCKET_ERROR;

        while (ret == SOCKET_ERROR) {
            //полчение ответа
            ret = recv(clientSocket, message, 1024, 0);
            //обработка ошибок
            if (ret == 0 || ret == WSAECONNRESET) {
                printf("[%s] Connection closed\n", getCurrentTime());
                break;
            }
            if (ret < 0) {
                //printf("Can't resieve message\n");
                /*closesocket(clientSocket);
                return;*/
                continue;
            }
            //вывод на экран количества полученных байт и сообщение
            printf("[%s] Receive: %s, includes %d bytes\n", getCurrentTime(), message, ret);
        }
    }

}