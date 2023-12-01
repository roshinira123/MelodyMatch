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

    //Added additional features based on .csv file
    string trackID; 
    double danceabilityFactor;
    double energyFactor; 
    double livenessFactor; 
    bool hasBeenRecommended;

 public:
    Song(string t, string g, string m, string a, string tId, double dF, double eF, double lF); //Changed constructor
    void changeRecommendation();
    void displayDetails();
    string getTitle();
    string getGenre();
    string getMood();
    string getArtist();

   //Added additional features based on .csv file
    string getTrackID(); 
    double getDancebilityFactor(); 
    double getEnergyFactor(); 
    double getLivenessFactor(); 

    bool getRecommendation();
};

#endif // SONG_H  