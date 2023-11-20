#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <string>
#include <vector>

class mainMenu {
private:
    std::vector<std::string> genres;
    std::vector<std::string> moods;
    std::vector<std::string> artists;

public:
    mainMenu(){
        
    }

    void setGenres(std::vector<std::string> g) {
        genres = g;
    }

    void setMoods(std::vector<std::string> m) {
        moods = m;
    }

    void setArtists(std::vector<std::string> a) {
        artists = a;
    }

    void getGenres() {
        std::cout << "Select your favorite genres (separated by space):\n";
        for (size_t i = 0; i < genres.size(); i++) {
            std::cout << i + 1 << ". " << genres[i] << std::endl;
        }
    }

    void getMoods() {
        std::cout << "Select your favorite moods (separated by space):\n";
        for (size_t i = 0; i < moods.size(); i++) {
            std::cout << i + 1 << ". " << moods[i] << std::endl;
        }
    }

    void getArtists() {
        std::cout << "Select your favorite artists (separated by space):\n";
        for (size_t i = 0; i < artists.size(); i++) {
            std::cout << i + 1 << ". " << artists[i] << std::endl;
        }
    }

    void suggestMusic() {
        // Assuming this method communicates with the backend and provides recommendations
        std::cout << "Based on your input, here are some recommendations:\n";
        std::cout << "1. Song 1\n";
        std::cout << "2. Song 2\n";
        std::cout << "3. Song 3\n";
    }
};

#endif