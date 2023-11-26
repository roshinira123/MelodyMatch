#include "../header/song.h"
#include <iostream>

using namespace std;

Song::Song(string t, string g, string m, string a) {
    title = t;
    genre = g;
    mood = m;
    artist = a;
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

bool Song::getRecommendation() {
    return this->hasBeenRecommended;
}