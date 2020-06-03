/**
 * @authors Stanislav Stoianov
 */

#include <malloc.h>
#include "UserEntety.h"

//TODO FIXME

void setName(char *name) {
     //User *User= ( struct User*) malloc(sizeof(struct User));
    User.name = name;
}

char *getName() {
    return User.name;
}