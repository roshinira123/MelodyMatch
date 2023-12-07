#include <iostream>
#include <string>
#include <vector>
#include "../header/mainMenu.h"
#include "../header/songsDataFilter.h"
using namespace std;


mainMenu::mainMenu(){

}

void mainMenu::displayMainMenu(){
    cout<<"Welcome to Melody Match!"<<endl;

}


void mainMenu::displayMusicOptions() {
    // Display music-related options for the user
    cout << "Choose an option:" << endl;
    cout << "0 - Quit" << endl;
    cout << "1 - Get personalized song list" << endl;
    
   
}

void mainMenu::personalizeSongs(){
    songsDataFilter dataFilter;
    string genre, artist, mood;
               
        // Get user input for genre, artist, and mood
        cout << "Enter the genre: ";
        cin >> genre;

        cout << "Enter the artist: ";
        cin >> artist;

        cout << "Enter the mood (energetic, happy, tired, sad, wildcard[IF you want some fun!] ): ";
        cin >> mood;


        // Filter songs based on user's choices
        dataFilter.getSongsByGenre(genre);
        dataFilter.getSongsByArtist(artist);
        dataFilter.getSongsByMood(mood);


        // Get personalized song list based on user choices
        vector<Song> personalizedSongs = dataFilter.personalizedSongList();
               
        // Display the personalized song list to the user
        cout << "Your personalized song list:" << endl;
        for (auto &song : personalizedSongs) {
                song.displayDetails();
        }

        dataFilter.clear();

}


int main() {
    mainMenu menu;


    bool exitProgram = false;
    int choice;


    while (!exitProgram) {
        menu.displayMainMenu();
        menu.displayMusicOptions();


        cout << "Enter your choice (0 to exit): ";
        cin >> choice;


        switch (choice) {
            case 0:
                exitProgram = true;
                break;
            case 1: {
                menu.personalizeSongs();
            }

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }


    return 0;
}
