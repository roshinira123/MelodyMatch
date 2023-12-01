#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include "/home/csmajs/aorde001/final-project-rrang020-abane029-dlian032-aorde001/header/SongsDataManager.h"

using namespace std;

void SongsDataManager::GetData(const std::string& filename) {
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
            Song newSong(title, genre, "", artist, trackID, danceability, energy, liveness);
            ListOfSongs.push_back(newSong);
        } else {
            cout << "Error parsing line: " << line << endl;
        }
    }

    file.close();
}

vector<Song> SongsDataManager::getSongs() const {
    return ListOfSongs;
}
