#include "../header/user.h"
#include "../header/loginAuth.h"
#include "gtest/gtest.h"


//Test LoginAuth class
TEST(LoginAuthTest, CheckUser) {
 

    loginAuth login("AO", "AO");
    login.setNewUser("AO","AO");

    EXPECT_TRUE(login.checkUser("AO","AO"));
}

TEST(LoginAuthTest, FalseUser) {
 
    loginAuth login("Roshini", "RR");
    login.setNewUser("Roshini","RR");

    EXPECT_FALSE(login.checkUser("Darren","hi"));
}

TEST(LoginAuthTest,AddUsers){
    //Password input is object creation loginauth
    loginAuth log("DarrenL","Darn");

    log.setNewUser("DarrenL","Darn");
    log.setNewUser("Aheli","AB");
    log.setNewUser("Ali","A");

    EXPECT_TRUE(log.checkUser("DarrenL","Darn"));
     EXPECT_FALSE(log.checkUser("Aheli","hi"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}