#include "../header/song.h"
#include <iostream>

using namespace std;

Song::Song(string t, string g, string a, string tId, double dF, double eF, double lF) {
    title = t;
    genre = g;
    artist = a;
    trackID = tId; 
    danceabilityFactor = dF; 
    energyFactor = eF; 
    livenessFactor = lF; 
    hasBeenRecommended = false;
}

void Song::changeRecommendation() {
    hasBeenRecommended = !hasBeenRecommended;
}

void Song::displayDetails() {
    cout << "Title: " << title << ", Genre: " << genre
        << ", Mood: " << getMood() << ", Artist: " << artist
        << " URL:https://open.spotify.com/track/" <<trackID <<endl;
}

string Song::getTitle() {
    return this->title;
}

string Song::getGenre() {
    return this->genre;
}

string Song::getMood() {
    //string m;
    if(this->danceabilityFactor > 0.6 && this->energyFactor >= 0.8 && this->energyFactor <= 1.0){
            this->mood = "energetic";
    }else if(this->danceabilityFactor >= 0.5 && this->energyFactor >= 0.5 && this->energyFactor < 0.8){
            this->mood = "happy";
    }else if(this->danceabilityFactor <= 0.5 && this->energyFactor>= 0.2 && this->energyFactor < 0.5){
            this->mood = "tired";
    }else if(this->danceabilityFactor < 0.4 && this->energyFactor >= 0 && this->energyFactor < 0.2){
            this->mood = "sad";
    }else{
        this->mood = "wildcard";
    }

    return this->mood;
}

string Song::getArtist() {
    return this->artist;
}

/*
void Song::setMood(string m){
    this->mood = m;
}
*/
string Song::getTrackID(){
    return this->trackID; //Added the prefix of the url so users can access the track immediately
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