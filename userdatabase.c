#include "userdatabase.h"
#include <stdio.h>

void userSave(const char *email){
    if(userExists(email)){
        return;
    }
    FILE *file = fopen("users.txt", "a");
    fprintf(file,"%s\n",email);
    fclose(file);
}
bool userExists(const char *email){
    FILE *file = fopen("users.txt", "r");
    if (file == NULL){
        return false;
    }

    char temp[512];
    while(fgets(temp, 512, file) != NULL) {
        if((strstr(temp, email)) != NULL) {
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}

int userRegistrationsToday(){
    return 1; //Now Hardcoded but you know what I mean
}
