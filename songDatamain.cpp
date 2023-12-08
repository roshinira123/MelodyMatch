#include <vector>
#include "header/songsDataManager.h"
#include "header/song.h"


int main() {
    songsDataManager s;
    s.GetData("Data/SpotifyFeatures - SpotifyFeatures.csv");

    vector<Song> songs = s.getSongs();

    return 0;
}