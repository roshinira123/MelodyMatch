// #include "../header/songsDataManager.h"
#include <vector>
#include "header/songsDataManager.h"
#include "header/song.h"


int main() {
    songsDataManager s;
    s.GetData("Data/SpotifyFeatures - SpotifyFeatures.csv");

    vector<Song> songs = s.getSongs();

    for (int i = 0; i < 140; i++) {
        songs.at(i).displayDetails();
    }

    //songs.at(132).displayDetails();

    return 0;
}