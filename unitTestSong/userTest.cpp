#include "gtest/gtest.h"

#include "../header/user.h"//header file

//Default Constructor
TEST(userTest,userDefault){
    //User obj
    User user1;

    //Expect
    EXPECT_EQ(user1.getUsername(),"");
    EXPECT_EQ(user1.getPassword(),"");
}

//Parameter Constructor
TEST(userTest,userObj){
    //User obj
    User user1("DarrenL", "Ilikecoffee1");

    //Expect
    EXPECT_EQ(user1.getUsername(),"DarrenL");
    EXPECT_EQ(user1.getPassword(),"Ilikecoffee1");
}

//NE Constructor
TEST(userTest,failedUserObj){
    //obj
    User user1("DL","Iliketea1");

    EXPECT_NE(user1.getUsername(),"DlR");
    EXPECT_NE(user1.getPassword(),"Iliketea");
}

//addUser to list
TEST(userTest,addUser){
    userList list1;
    User user1("Roshini","RR");

    list1.addUser(user1);
     // Verify that the user is in the list
    EXPECT_TRUE(list1.userExists(user1.getUsername()));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}