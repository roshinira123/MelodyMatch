#ifndef SONG_H
#define SONG_H

#include <iostream>

class Song{
    //private vars
    private:
    std::string artist;
    std::string name;
    int length;
    std::string genre;

    public:
    //Constructor
    Song(std::string artist,std::string name, int length, std::string genre)
        : artist(artist), name(name), length(length), genre(genre) {}

    //getters
    std::string getArtist() const {
        return artist;
    }

    std::string getName() const {
        return name;
    }

    int getLength() const {
        return length;
    }

    std::string getGenre() const {
        return genre;
    }
};

#endif