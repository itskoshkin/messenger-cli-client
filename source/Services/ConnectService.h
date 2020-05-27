/**
 * @authors Stanislav Stoianov, Daria Pavlova
 */

#include <winsock.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifndef CLIENT_CONNECTSERVICE_H

void connectToServer(SOCKET clientSocket);

void dissconnetFromServer(SOCKET socket);

#define CLIENT_CONNECTSERVICE_H

#endif
