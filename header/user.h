#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>

//Add a Validation Class
//how to add a validation class
//Error Expectation

//Internal Class
//Assertions

//login information is incorrect. Also not say 
//something like Incorrect Password, Try again?
//Giving free information
//Incorrect Username or Password is better

//Error msgs need to be clean or sanitized to prevent SQl injections
//or attacks

//Keep Emergent Design in Mind

//Create Issue for Refactoring

//Code Smells are warning signs

class User{
    //private vars
    private:
    std::string password;
    std::string username;

    public:
    //default Constructor
    User();

    //Parameter Constructor
    User(const std::string & user, const std::string & pass);

    /*GETTERS*/
    std::string getUsername() const;
    std::string getPassword() const;

    /*SETTERS*/
    void setUsername(const std::string& newUser);
    void setPassword(const std::string& newPass);

    /*Display MSG*/ 
    void displayUserInfo() const;
};

class userList{
    private:
    std::vector <User> list;

    public:
    //default Constructor
    userList();

    //Functions
    void addUser(const User &newUser );

    void removeUser(const std::string &username);

    bool userExists(const std::string &username) const;

    void displayAllUsers() const;

    int getUserCount() const;
};

#endif