#include "../header/user.h"
#include "gtest/gtest.h"

// Default Constructor
User::User() 
{
    username = "";
    password = "";
}

// Parameter Constructor
User::User(const std::string &user, const std::string &pass){
    username = user;
    password = pass;
}

/* GETTERS */
std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

/* SETTERS */
void User::setUsername(const std::string &newUser) {
    username = newUser;
}

void User::setPassword(const std::string &newPass) {
    password = newPass;
}


//Displaying user information
void User::displayUserInfo() const {
    std::cout << "Username: " << username << "\n";
    std::cout << "Password: " << password << "\n";
}

/*
    UserList Class
*/

// Default Constructor
userList::userList() {}

//Add a User to the List
void userList::addUser(const User &newUser) {
     // Check if the username already exists
    if (!userExists(newUser.getUsername())) {
        list.push_back(newUser);
    } else {
       EXPECT_FALSE(userExists(newUser.getUsername())) << "Error: User with username " 
                    << newUser.getUsername() << " already exists.";
    }
}

//Remove a User from the List
void userList::removeUser(const std::string &username) {
    for(auto i = list.begin(); i != list.end();++i){
        if(i->getUsername() == username){
            list.erase(i);
            i--;
        }
    }
}

//Check if a User Exists in the List
bool userList::userExists(const std::string &username) const {
   for (auto &user : list) {
        if (user.getUsername() == username) {
            return true;  // User found
        }
    }
    return false;  // User not found
}

//Display All Users in the List
void userList::displayAllUsers() const {
    for (auto &user : list) {
        std::cout << "Username: " << user.getUsername() << "\n";
    }
}

//Get the Number of Users in the List
int userList::getUserCount() const {
    return static_cast<int>(list.size());
}

