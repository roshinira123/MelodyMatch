#include "/home/csmajs/aorde001/final-project-rrang020-abane029-dlian032-aorde001/header/songsDataManager.h"
#include <vector>


int main() {
    songsDataManager s;
    s.GetData("/home/csmajs/aorde001/final-project-rrang020-abane029-dlian032-aorde001/Data/SpotifyFeatures - SpotifyFeatures.csv");

    vector<Song> songs = s.getSongs();

    for (int i = 0; i < 10; i++) {
        songs.at(i).displayDetails();
    }

    return 0;
}
