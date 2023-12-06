#include "../header/user.h"
#include "../header/loginAuth.h"

#include <string>
#include <iostream>
using namespace std;

int main()
{
    //User input 
    string username;
    string password;
    char choice;
    //boolean
    bool check;

    cout << "Hi, Please enter username:";
    cin >> username;
    cout << "Now enter your password:";
    cin >> password;

    //object
    loginAuth loginInfo;
    loginInfo.setNewUser("Roshini","R");

    check = loginInfo.checkUser(username);
    if(check == false){
        cout << "Are you a new user(Y|N)?"<< endl;
        cin >> choice;
        if(choice == 'Y'){
            cout << "Enter a username to create a new account:";
            cin >> username;
            cin >> password;
            loginInfo.setNewUser(username,password);
            cout << "Checking username in list";
            loginInfo.checkUser(username);
        }else{
           loginInfo.printLoginSuccess();
        }       
    }else{
           loginInfo.printLoginSuccess();
    }
}