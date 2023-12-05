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
        string genre, artist, title, trackID;
        string tempTitle;
        double danceability, energy, liveness;

        getline(iss, genre, ',');
        getline(iss, artist, ',');
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
        iss >> danceability >> energy >> liveness;
        //Create a new Song object and add it to the ListOfSongs vector
        Song newSong(title, genre, "BLANK", artist, trackID, danceability, energy, liveness);
        ListOfSongs.push_back(newSong);        
    }
    file.close();
}

vector<Song> songsDataManager::getSongs() const {
    return ListOfSongs;
}


