#include "../header/loginAuth.h"

//Default Constructor
loginAuth::loginAuth() {
    username = "";
    password = "";
    isCorrectUser = false;
}

//Parametrized Constructor
loginAuth::loginAuth(const std::string & user, const std::string & pass){
    username = user;
    password = pass;
    isCorrectUser = false;
}

//Authentication
bool loginAuth::checkUser(const std::string & username) {
        User user1 = list1.getUser(username);

        if (user1.getUsername() == username && user1.getPassword() == password) {
            setBoolUser(true);
            printLoginSuccess();
            return true; // Authentication successful
        }else{
            setBoolUser(false);
            printLoginSuccess();
            return false; // Authentication failed
        }
}

//setter Function for isCorrectUser
void loginAuth::setBoolUser(bool check) {
    isCorrectUser = check;
}

//setter for a new user
void loginAuth::setNewUser(const std::string &newUsername, const std::string &newPassword) {
    // Create a new user and add it to the list
    User newUser(newUsername, newPassword);
    list1.addUser(newUser);

    std::cout << "New user created with username: " << newUsername << std::endl;
}

/*GETTERS*/
//getter for username
std::string loginAuth::getUsername() const {
    return username;
}

//getter for password
std::string loginAuth::getPassword() const {
    return password;
}

//getter for isCorrectUser
bool loginAuth::getBoolUser() const{
    return isCorrectUser;
}


//temporary login msg 
void loginAuth::printLoginSuccess(){
    if(getBoolUser() == true)
    {
        std::cout << "You have successfully logged in!" << std::endl;
    }else{
        std::cout << "Fail. Please enter username and password again.";
    }
}