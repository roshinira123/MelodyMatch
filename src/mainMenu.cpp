#include <iostream>
#include <string>
#include <vector>
#include "../header/mainMenu.h"
#include "../header/songsDataFilter.h"
using namespace std;


mainMenu::mainMenu(){

}

void mainMenu::displayMainMenu(){


    cout<<"Welcome to Melody Match"<<endl;


}


void mainMenu::displayMusicOptions() {
    // Display music-related options for the user
    std::cout << "Choose an option:" << std::endl;
     std::cout << "0. Quit" << std::endl;
    std::cout << "1. Get personalized song list" << std::endl;
   
}


int main() {
    mainMenu menu;
    songsDataFilter dataFilter;


    bool exitProgram = false;
    int choice;


    while (!exitProgram) {
        menu.displayMainMenu();
        menu.displayMusicOptions();


        std::cout << "Enter your choice (0 to exit): ";
        std::cin >> choice;


        switch (choice) {
            case 0:
                exitProgram = true;
                break;
            case 1: {
                std::string genre, artist, mood;
               
                // Get user input for genre, artist, and mood
                std::cout << "Enter the genre: ";
                std::cin >> genre;


                std::cout << "Enter the artist: ";
                std::cin >> artist;


                std::cout << "Enter the mood (energetic, happy, tired, sad, wildcard[IF you want some fun!] ): ";
                std::cin >> mood;


                // Filter songs based on user's choices
                dataFilter.getSongsByGenre(genre);
                dataFilter.getSongsByArtist(artist);
                dataFilter.getSongsByMood(mood);


                // Get personalized song list based on user choices
                std::vector<Song> personalizedSongs = dataFilter.personalizedSongList();
               
                // Display the personalized song list to the user
                std::cout << "Your personalized song list:" << std::endl;
                for (const auto &song : personalizedSongs) {
                    // Display song details (e.g., song name, artist, etc.)
                }
                // Clear options for the next iteration
                dataFilter.~songsDataFilter();
                break;
            }
            // Add more cases for other options if needed


            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }


    return 0;
}
