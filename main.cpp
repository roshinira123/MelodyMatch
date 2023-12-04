#include "/home/csmajs/aorde001/final-project-rrang020-abane029-dlian032-aorde001/header/songsDataManager.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
    songsDataFilter s;
    s.GetData("/home/csmajs/aorde001/final-project-rrang020-abane029-dlian032-aorde001/Data/SpotifyFeatures - SpotifyFeatures.csv");

    vector<Song> songs = s.getSongs();

    for (int i = 0; i < 140; i++) {
        songs.at(i).displayDetails();
    }

    cout << endl;

    s.getSongsByGenre("Movie");
    s.getSongsByArtist("Henri Salvador");
    s.getSongsByMood("happy");
    cout << s.personalizedSongList() << endl;

    return 0;
}







/*
#include <iostream>
#include <string>
#include <vector>
#include "songsDataFilter.h"

int main()
{
    songsDataFilter algo;
    vector<string> personalizedSongs;

    string genre;
    string artist;
    string mood;

    vector<string> songsByGenre{"Movie","Movie","R&B","A Cappella","Country","Alternative"};
    vector<string> songsByArtist{"Henri Salvador","Martin & les fées","Yo Trane","MC6 A Cappella","Keith Urban","Linkin Park"};
    vector<string> songsTitles{"C'est beau de faire un Show","Perdu d'avance (par Gad Elmaleh)","High off You","For the Longest Time","Boy Gets A Truck","In the End"};
    vector<double> songsByEnergy{0.91,0.737,0.319,0.298,0.693,0.853};

    cout << "List genre: " << endl;
    cin >> genre;

    cout << "List artist: " << endl;
    cin >> artist;

    cout << "List mood: " << endl;
    cin >> mood;

    algo.addSongsByGenre(songsByGenre, songsTitles, &personalizedSongs, genre);
    algo.addSongsByArtist(songsByArtist, songsTitles, &personalizedSongs, artist);
    algo.addSongsByMood(songsByEnergy, songsTitles, &personalizedSongs, mood);
*/