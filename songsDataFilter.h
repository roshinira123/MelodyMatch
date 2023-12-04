#ifndef SONGSDATAFILTER_H
#define SONGSDATAFILTER_H

#include <iostream>
#include <string>
#include <vector>
#include "../header/song.h"
#include "../header/songsDataManager.h"

class songsDataFilter: public songsDataManager
{
private:
    vector<Song> SongsByGenre;
    vector<Song> SongsByArtist;
    vector<Song> SongsByMood;
    vector<Song> personalizedSongs;

public:
    songsDataFilter() {};
    void getSongsByGenre(const string &genre);
    void getSongsByArtist(const string &artist);
    void getSongsByMood(const string &mood);
    vector<Song> personalizedSongList();
};

#endif