#include <iostream>
#include "../header/user.h"
#include "../header/loginAuth.h"

using namespace std;

int main() {
    loginAuth authSystem;
    string inputUsername, inputPassword;
    authSystem.setNewUser("Roshini", "hi");

    cout << "Do you have an account? (yes/no): ";
    string hasAccount;
    cin >> hasAccount;

    if (hasAccount == "yes") {
        cout << "Enter your username: ";
        cin >> inputUsername;
        cout << "Enter your password: ";
        cin >> inputPassword;

        if (authSystem.checkUser(inputUsername, inputPassword)) {
            authSystem.printLoginSuccess();
        } else {
            cout << "Failed to log in. Please try again or create a new account." << endl;
        }
    } else if (hasAccount == "no") {
        cout << "Create a new account" << endl;
        cout << "Enter a username: ";
        cin >> inputUsername;
        cout << "Enter a password: ";
        cin >> inputPassword;

        authSystem.setNewUser(inputUsername, inputPassword);
        cout << "New account created! You can now log in." << endl;
    } else {
        cout << "Invalid input. Please type 'yes' or 'no'." << endl;
    }

    return 0;
}