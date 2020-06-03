/**
 * @authors Stanislav Stoianov
 */

#include <winsock.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifndef CLIENT_CONNECTSERVICE_H

void connectToServer(SOCKET * clientSocket);

void disconnetFromServer(const SOCKET * clientSocket);

#define CLIENT_CONNECTSERVICE_H

#endif
