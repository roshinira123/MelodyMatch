#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include "../header/songsDataManager.h"
#include "../header/song.h"

using namespace std;

void songsDataManager::GetData(const std::string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    bool isFirstLine = true;
    while (getline(file, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            continue;  //Skip the first line
        }
        istringstream iss(line);
        string genre, artist, title, trackID, danceabilityStr, energyStr, livenessStr;
        string tempTitle, tempArtist;
        double danceability, energy, liveness;

        getline(iss, genre, ',');
        //Deal with commas within artist name
        if (iss.peek() == '"') {
            iss.ignore();
            getline(iss, artist, '"');
            while (iss.peek() == '"') {
                artist += '"';
                iss.ignore(); 
                getline(iss, tempArtist, '"');
                artist += tempArtist;
            }
            if (iss.peek() == ',') {
                iss.ignore();
            }
        }
        else {
            getline(iss, artist, ',');
        }        
        //Deal with commas within title
        if (iss.peek() == '"') {
            iss.ignore();
            getline(iss, title, '"');
            while (iss.peek() == '"') {
                title += '"';
                iss.ignore(); 
                getline(iss, tempTitle, '"');
                title += tempTitle;
            }
            if (iss.peek() == ',') {
                iss.ignore();
            }
        }
        else {
            getline(iss, title, ',');
        }
        getline(iss, trackID, ',');
        getline(iss, danceabilityStr, ',');
        getline(iss, energyStr, ',');
        getline(iss, livenessStr);

        //Convert danceability/energy/liveness strings into doubles
        try {
            danceability = stod(danceabilityStr);
            energy = stod(energyStr);
            liveness = stod(livenessStr);
        } catch (const invalid_argument& error) {
            cout << "Error converting string to double: " << error.what() << " " << line;
            return;
        }
        //Create a new Song object and add it to the ListOfSongs vector
        Song newSong(title, genre, artist, trackID, danceability, energy, liveness);
        ListOfSongs.push_back(newSong);        
    }
    file.close();
}

vector<Song> songsDataManager::getSongs() const {
    return ListOfSongs;
}
