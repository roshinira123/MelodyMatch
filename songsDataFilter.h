#ifndef SONGSDATAFILTER_H
#define SONGSDATAFILTER_H

#include <iostream>
#include <string>
#include <vector>

class songsDataFilter
{
private:
    std::vector<std::string> songsByGenre;
    std::vector<std::string> songsByGenre;
    std::vector<std::string> songsByMood;
    std::vector<std::string> songsByArtist;
    std::vector<std::string> personalizedSongs;

public:

    void getSongsByGenre(std::vector<std::string> songsByGenre) {};
    void getSongsByMood(std::vector<std::string> songsByMood) {};
    void getSongsByArtist(std::vector<std::string> songsByArtist) {};
};

#endif