#ifndef __USERDATABASE_H
#define __USERDATABASE_H

#include <stdbool.h>

void userSave(const char *email);
bool userExists(const char *email);
int userRegistrationsToday();

#endif //__USERDATABASE_H