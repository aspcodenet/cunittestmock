#include <stdio.h>
#include "registration.h"

int main(){
    char email[100] ;
    while(1){
        printf("Ange email:");
        scanf(" %s",email);
        REGISTRATION_STATUS status = registerUser(email);
        switch(status){
            case REGISTRATION_STATUS_OK:
            printf("OK\n");
            break;
            case REGISTRATION_STATUS_WRONG_EMAIL_DOMAIN:
            printf("Not valid email\n");
            break;
            case REGISTRATION_STATUS_ALREADY_REGISTERED:
            printf("Already registered\n");
            break;
            case REGISTRATION_STATUS_TOO_MANY_REGISTRATIONS_TODAY:
            printf("Too many today\n");
            break;
            }
    }
    return 0;
}