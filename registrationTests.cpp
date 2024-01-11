#include "registration.h"
#include <gtest/gtest.h>
#include "fff.h"

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(userSave,const char *);
FAKE_VALUE_FUNC(bool,userExists,const char *);



// 1. Vi vill göra unittester trots att dom använder externa "units" (funktioner i andra filer osv)
//2. Vi skapar FAKES (egna implementationer de externa funktionena som vår unit anropas)
//3. Vi testar BARA logiken i själva unitens funktion
//4. felvärden+ att de andra funktionerna anropas NÄR DE SKA ANROPAS - och att det är rätt parametrar
//5. Vi arrangerar värden med MOCKS/FAKES
//6.- fakes som vi sett dom nu idag verkar jättejobbigt


// Funktioner - 
// kan fylla två syften
//          - undvika DRY (anropas flera gånger)
//          ---> självdokumenterande kod
//          - kortare kod

// Mock och testning

//   virtual metoder privata metoder osv
//      OBJEKT = black box testing - vi testar publika metoder (inte privata)

// FAKE, MOCKS - fff.h eller google mock gör

// bool userSavedHasBeenCalled = false;
// char userSaveCalledWith[100];
// void userSave(const char *email){
//     strcpy(userSaveCalledWith,email);
//     userSavedHasBeenCalled = true;
// }

// bool userExistsShouldReturn = false;
// bool userExists(const char *email){
//     printf("stefans userexists\n");
//     return userExistsShouldReturn;
// }

// int userRegistrationsToday(){
//     return 1;
// }
// void sendWelcomeEmailToUser(const char *email){
    
// }
class RegistrationTests : public testing::Test {

protected:
	void SetUp() override {
        RESET_FAKE(userSave);
        RESET_FAKE(userExists);
		//game_initialize();	/* Without this the Tests could break*/
	}
};


// om allt är ok så ska ett email skickas!
// -> om allt är ok så ska vi ha "delegerat" /sagt till att ett mail ska skickas

TEST_F(RegistrationTests, whenWrongDomainShouldGetCorrectError){
    // ARRANGE
    char *email = "stefan@stefan.se";
    
    // ACT
    REGISTRATION_STATUS status = registerUser(email);


    //ASSERT    
    ASSERT_EQ(status,REGISTRATION_STATUS_WRONG_EMAIL_DOMAIN);
}





TEST_F(RegistrationTests, whenAlreadyRegisteredShouldGetCorrectError){
    // ARRANGE
    // om vi kan få userExists att returnera true så 
    userExists_fake.return_val = true;
    char *email = "stefan@hej.se";
    
    // ACT
    REGISTRATION_STATUS status = registerUser(email);


    //ASSERT    
    ASSERT_EQ(status,REGISTRATION_STATUS_ALREADY_REGISTERED);
}




TEST_F(RegistrationTests, whenOkUserShouldBeSaved){
    // ARRANGE
    // om vi kan få userExists att returnera false
    userExists_fake.return_val = false;

    char *email = "stefan@hej.se";
    
    // ACT
    REGISTRATION_STATUS status = registerUser(email);


    //ASSERT    
    ASSERT_EQ(userSave_fake.call_count,1);
}




TEST_F(RegistrationTests, whenOkCorrectUserShouldBeSaved){
    // ARRANGE
    // om vi kan få userExists att returnera false
    char *email = "stefan@hej.se";
    
    // ACT
    REGISTRATION_STATUS status = registerUser(email);


    int i = strcmp(email,userSave_fake.arg0_val);
    //ASSERT    
    ASSERT_EQ(i,0);
}




