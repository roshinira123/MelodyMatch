#include <iostream>
#include <vector>
#include "header/songsDataManager.h"
#include "header/song.h"
#include "header/songsDataFilter.h"

using namespace std;

int main() {
    songsDataFilter dataFilter;

    songsDataManager dataManager; 
    dataManager.GetData("Data/SpotifyFeatures - SpotifyFeatures.csv");
   
    dataFilter.getSongsByGenre("R&B");
    dataFilter.getSongsByArtist("Joji");
    dataFilter.getSongsByMood("happy");

    vector<Song> personalizedList = dataFilter.personalizedSongList();
   
    for (auto &song : personalizedList)
    {
        song.displayDetails();
    }

    return 0;
}