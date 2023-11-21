#include "../header/loginAuth.h"
//Default Constructor
loginAuth::loginAuth() {
    username = "";
    password = "";
    isCorrectUser = false;
}

//Parametrized Constructor
loginAuth::loginAuth(std::string user, std::string pass) {
    username = user;
    password = pass;
    isCorrectUser = false;
}

bool loginAuth::checkUser() {
    //Pull user data from Spotify API?

    //temp check 
    if(username == spotifyUser && password == spotifyPass){
        setBoolUser(true);
    }else if {
        setBoolUser(false);
    }
    return getBoolUser();
}

//setter Function for isCorrectUser
void loginAuth::setBoolUser(bool check) {
    isCorrectUser = check;
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
void printLoginSuccess(){
    if(isCorrectUser == true)
    {
        cout << "You have successfully logged in!" << endl;
    }else{
        cout << "Fail. Please enter username and password again.";
    }
}