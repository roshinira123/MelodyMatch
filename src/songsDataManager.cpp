#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include "/home/csmajs/aorde001/final-project-rrang020-abane029-dlian032-aorde001/header/songsDataManager.h"

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
        double danceability, energy, liveness;

        if (getline(iss, genre, ',') &&
            getline(iss, artist, ',') &&
            getline(iss, title, ',') &&
            getline(iss, trackID, ',')) {

            iss >> danceability >> energy >> liveness;
            //Create a new Song object and add it to the ListOfSongs vector
            Song newSong(title, genre, "[TEMP BLANK]", artist, trackID, danceability, energy, liveness);
            ListOfSongs.push_back(newSong);
        } else {
            cout << "Error parsing line: " << line << endl;
        }
    }

    file.close();
}

vector<Song> songsDataManager::getSongs() const {
    return ListOfSongs;
}
