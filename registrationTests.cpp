#include "registration.h"
#include <gtest/gtest.h>

class RegistrationTests : public testing::Test {
protected:
	void SetUp() override {
		//game_initialize();	/* Without this the Tests could break*/
	}
};

TEST_F(RegistrationTests, whenWrongDomainShouldGetCorrectError){
    char *email = "stefan@stefan.se";
    
    REGISTRATION_STATUS status = registerUser(email);

    ASSERT_EQ(status,REGISTRATION_STATUS_WRONG_EMAIL_DOMAIN);
}
