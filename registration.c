#include <stdbool.h>
#include <string.h>
#include "registration.h"
#include "userdatabase.h"
#include "email.h"


bool verifyEmailDomain(const char *email){
    if(strstr(email,"hej.se") ||  strstr(email,"hej.com") ){
        return true;
    }
    return false;
}



REGISTRATION_STATUS registerUser(const char *email){
  if (!verifyEmailDomain(email)){
    return REGISTRATION_STATUS_WRONG_EMAIL_DOMAIN;
  }
  if (userExists(email)){
    return REGISTRATION_STATUS_ALREADY_REGISTERED;
  }
  if (userRegistrationsToday() >=10 ){
    return REGISTRATION_STATUS_TOO_MANY_REGISTRATIONS_TODAY;
  }
    userSave(email);
    sendWelcomeEmailToUser(email);
    return REGISTRATION_STATUS_OK;    
}

