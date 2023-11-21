#ifndef SONG_H
#define SONG_H

#include <iostream>

class loginAuth{
    //private vars
    private:
    std::string password;
    std::username;
    bool isCorrectUser;

    public:
    //default Constructor
    loginAuth();

    //Parameter Constructor
    loginAuth(const std::string & user, const std::string & pass)

    //authentication
    bool checkUser();

    /*GETTERS*/
    std::string getUsername() const;
    std::string getPassword() const;
    bool getBoolUser() const;

    /*SETTERS*/
    void setBoolUser(bool check);

    /*Display MSG*/
    
};

#endif