#ifndef SONGSDATAMANAGER_H
#define SONGSDATAMANAGER_H

#include <fstream>
#include <sstream>
#include <vector>
#include "../header/song.h"

using namespace std;

class SongsDataManager {
private:
    vector<Song> ListOfSongs;

public:
    //Function to read data from the CSV file and populate ListOfSongs
    void GetData(const string& filename);

    //Function to get the ListOfSongs vector
    vector<Song> getSongs() const;
};

#endif // SONGSDATAMANAGER_H
