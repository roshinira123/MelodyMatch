#include <iostream>
#include <string>
#include <vector>
#include "../header/mainMenu.h"
#include "../header/songsDataFilter.h"
using namespace std;


mainMenu::mainMenu(){

}


void mainMenu::displayMusicOptions() {
    // Display music-related options for the user
    cout<<endl;
    cout << "Welcome to Melody Match!!!"<<endl;
    cout << "Choose an option (either 0 or 1):" << endl;
    cout << "1 - Get personalized song list" << endl;
    cout << "0 - Quit" << endl;
    cout<<endl;
   
   
}

void mainMenu::personalizeSongs(){
    songsDataFilter dataFilter;
    string genre, artist, mood;
               
        // Get user input for genre, artist, and mood
        cout<<"Please type out your exact genre choice from this list:"<<endl;
        cout<<"Movie, R&B, A Capella, Country, Alternative, Country, Dance, Hip-Hop, Pop, Folk, Rap, Ska, Soul" <<endl;
        cout <<"Enter the genre: ";
        cin >> genre;

         cout<<"Please type out your favorite artist some examples to try are: Adele, Joji, RCKB"<<endl;
        cout << "Enter the artist: ";
        cin >> artist;

        cout << "Enter the mood (energetic, happy, tired, sad, wildcard[IF you want some fun!] ): ";
        cin >> mood;

        cout<<endl;
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
        }
        cout<<endl;
        cout<<"Now add your favorites to your Spotify playlists using the URL link "<<endl;
        cout<<"Note: The list size will vary based on inputs"<<endl;
        cout<<"Feel free to create a new lists of songs, the possibilities are endless!"<<endl;
        cout<<endl;


        dataFilter.clear();

}


int main() {
    mainMenu menu;


    bool exitProgram = false;
    int choice;


    while (!exitProgram) {
       // menu.displayMainMenu();
        menu.displayMusicOptions();


        cout << "Enter your choice (0 to exit): ";
        cin >> choice;


        switch (choice) {
            case 0:
                cout<<"Thank you for using Melody Match! Have a fun with your new songs!"<<endl;
                exitProgram = true;
                break;
            case 1: {
                menu.personalizeSongs();
                break;
            }

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }


    return 0;
}
