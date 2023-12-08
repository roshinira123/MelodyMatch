#include <iostream>
#include <string>
#include <vector>
#include "../header/mainMenu.h"
#include "../header/songsDataFilter.h"
#include "../header/loginAuth.h"
using namespace std;


int main() {
    mainMenu menu;

    //Login stuff 
    cout<<"Welcome to Melody Match Login"<<endl;
    cout<<"Please login to start falling in love with new music."<<endl;
   
    
    menu.LoginHandler();
    cout<<endl;
   
    bool exitProgram = false;
    string choice;
    while (!exitProgram) {
       // menu.displayMainMenu();
        menu.displayMusicOptions();

        cout << "Enter your choice (0 to exit): ";
        getline(cin, choice);


        if (choice == "0") {
            cout<<"Thank you for using Melody Match! Have fun with your new songs!"<<endl;
            exitProgram = true;
        }
        else if (choice == "1") {
            menu.personalizeSongs();
        }
        else {
                cout << "Invalid choice. Please try again." << endl;
        }
    }


    return 0;
}
