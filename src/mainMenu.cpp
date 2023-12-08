#include <iostream>
#include <string>
#include <vector>
#include "../header/mainMenu.h"
#include "../header/songsDataFilter.h"
#include "../header/loginAuth.h"
using namespace std;


mainMenu::mainMenu(){

}


void mainMenu::displayMusicOptions() {
    // Display music-related options for the user
    cout<<"--------------------------------------------------"<<endl;
    cout << "Welcome to Melody Match!!!"<<endl;
    cout << "Choose an option (either 0 or 1):" << endl;
    cout << "1 - Get personalized song list" << endl;
    cout << "0 - Quit" << endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<endl;
   
   
}

void mainMenu::personalizeSongs(){
    songsDataFilter dataFilter;
    string genre, artist, mood;
               
        // Get user input for genre, artist, and mood
        cout<<"Please type out your exact genre choice from this list:"<<endl;
        cout<<"Movie, R&B, A Capella, Country, Alternative, Country, Dance, Hip-Hop, Pop, Folk, Rap, Ska, Soul" <<endl;
        cout <<"Enter the genre: ";

        getline(cin, genre);

        cout<<"Please type out your favorite artist some examples to try are: Adele, Joji, Britney Spears"<<endl;
        cout << "Enter the artist: ";

        getline(cin, artist);

        cout << "Enter the mood (energetic, happy, tired, sad, wildcard[IF you want some fun!] ): ";

        getline(cin, mood);

        // Filter songs based on user's choices
        dataFilter.getSongsByGenre(genre);
        dataFilter.getSongsByArtist(artist);
        dataFilter.getSongsByMood(mood);


        // Get personalized song list based on user choices
        vector<Song> personalizedSongs = dataFilter.personalizedSongList();
               
        // Display the personalized song list to the user
        cout<<endl;
        cout << "Here is your personalized song list:" << endl;
       
        int counter = 1;
        for (auto &song : personalizedSongs) {
                cout<<counter<<". ";
                song.displayDetails();
                counter++;
                cout<<endl;
        }
        cout<<endl;
        cout<<"Now add your favorites to your Spotify playlists using the URL link "<<endl;
        cout<<"Note: The list size will vary based on inputs"<<endl;
        cout<<"Feel free to create a new lists of songs, the possibilities are endless!"<<endl;
        cout<<endl;


        dataFilter.clear();

}

void mainMenu::LoginHandler(){
    loginAuth authSystem;
    string inputUsername, inputPassword;
    //Made a user just to load the system with someone
    authSystem.setNewUser("Roshini", "hi");

    bool exitLogin = false; 
    while(!exitLogin){
        cout<<endl;
        cout << "Do you have an account? (yes/no): ";
        string hasAccount;
        getline(cin,hasAccount);
        cout<<endl;

        if (hasAccount == "yes") {
            cout << "Enter your username: ";
            getline(cin,inputUsername);
            cout << "Enter your password: ";
            getline(cin,inputPassword);

            if (authSystem.checkUser(inputUsername, inputPassword)) {
                authSystem.printLoginSuccess();
                exitLogin = true; 

            } else {
                cout << "Failed to log in. Please try again or create a new account." << endl;
            }
        } else if (hasAccount == "no") {
            cout << "Create a new account" << endl;
            cout << "Enter a username: ";
            getline(cin,inputUsername);
            cout << "Enter a password: ";
            getline(cin,inputPassword);

            authSystem.setNewUser(inputUsername, inputPassword);
            cout << "New account created! You can now log in." << endl;
        } else {
            cout << "Invalid input. Please type 'yes' or 'no'." << endl;
        }
    }
    

}


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
