/**
 * @authors Stanislav Stoianov
 */

#include <malloc.h>
#include "UserEntety.h"

//TODO FIXME

void getName(char *name) {
    struct User = (struct User) malloc(sizeof(struct User));
    User.name = name;
}

char *setName() {
    return User.name;
}