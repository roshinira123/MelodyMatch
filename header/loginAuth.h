#ifndef LOGINAUTH_H
#define LOGINAUTH_H
#include "../header/user.h"
#include <iostream>
#include <string>

//if new user create new user and insert it into list
//

class loginAuth{
    //private vars
    private:
    std::string password;
    std::string username;
    bool isCorrectUser;
    //list of Users
    userList list1;

    public:
    //default Constructor
    loginAuth();

    //Parameter Constructor
    loginAuth(const std::string & user, const std::string & pass);

    //authentication
    bool checkUser(const std::string & inputUsername,const std::string & inputPassword);

    /*GETTERS*/
    std::string getUsername() const;
    std::string getPassword() const;
    bool getBoolUser() const;

    /*SETTERS*/
    void setBoolUser(bool check);
    //set new password
    void setPassword(const std::string & pass);

    void setNewUser(const std::string &newUsername, const std::string &newPassword);


    /*Display MSG*/ 
    void printLoginSuccess();

};

#endif