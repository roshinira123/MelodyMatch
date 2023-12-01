#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

class Song {
 private:
    string title;
    string genre;
    string mood;
    string artist;
    bool hasBeenRecommended;

 public:
    Song(string t, string g, string m, string a);
    void changeRecommendation();
    void displayDetails();
    string getTitle();
    string getGenre();
    string getMood();
    string getArtist();
    bool getRecommendation();
};

#endif // SONG_H  