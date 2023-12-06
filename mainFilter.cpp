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

    //vector<Song> songs = s.getSongs();

   
    dataFilter.getSongsByGenre("Pop");
    dataFilter.getSongsByArtist("Adele");
    dataFilter.getSongsByMood("sad");

    vector<Song> personalizedList = dataFilter.personalizedSongList();

   
     for (auto &song : personalizedList) {
        song.displayDetails();
    }

   

    return 0;
}