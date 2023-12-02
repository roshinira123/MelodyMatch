#ifndef SONGSDATAFILTER_H
#define SONGSDATAFILTER_H

#include <iostream>
#include <string>
#include <vector>

class songsDataFilter
{

private:

    string genre;
    string mood;
    string artist;
    string title;
    string newSong;

    vector<string> genres;
    vector<string> moods;
    vector<string> artists;
    vector<string> titles;

public:
    songsDataFilter() {};
    void addSongsByGenre(vector<string> &songsByGenre, vector<string> songsTitles, vector<string> &personalizedSongs, string genre) {};
    void addSongsByArtist(vector<string> &songsByArtist, vector<string> songsTitles, vector<string> &personalizedSongs, string artist) {};
    void addSongsByMood(vector<string> &songsByEnergy, vector<string> songsTitles, vector<string> &personalizedSongs, string mood) {};
};

#endif