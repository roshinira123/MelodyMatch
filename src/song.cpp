#include "../header/song.h"
#include <iostream>

using namespace std;

Song::Song(string t, string g, string m, string a, string tId, double dF, double eF, double lF) {
    title = t;
    genre = g;
    mood = m;
    artist = a;
    trackID = tID; 
    danceabilityFactor = dF; 
    energyFactor = eF; 
    livenessFactor = lF; 
    hasBeenRecommended = false;
}

void Song::changeRecommendation() {
    hasBeenRecommended = !hasBeenRecommended;
}

//Maybe
void Song::displayDetails() {
    cout << "Title: " << title << ", Genre: " << genre
        << ", Mood: " << mood << ", Artist: " << artist
        << ", Recommended: " << (hasBeenRecommended ? "Yes" : "No") << endl;
}

string Song::getTitle() {
    return this->title;
}

string Song::getGenre() {
    return this->genre;
}

string Song::getMood() {
    return this->mood;
}

string Song::getArtist() {
    return this->artist;
}

string Song::getTrackID(){
    return "https://open.spotify.com/track/" + this->trackID; //Added the prefix of the url so users can access the track immediately
}

double Song::getDancebilityFactor(){
    return this->danceabilityFactor; 
}
double Song::getEnergyFactor(){
    return this->energyFactor; 
}

double Song::getLivenessFactor(){
    return this->livenessFactor; 
}

bool Song::getRecommendation() {
    return this->hasBeenRecommended;
}