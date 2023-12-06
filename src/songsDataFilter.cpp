#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include "../header/songsDataManager.h"
#include "../header/song.h"
#include "../header/songsDataFilter.h"

void songsDataFilter :: getSongsByGenre(const string &genre) //select 5 songs from user's genre and add them to songsByGenre vector
{
    songsDataManager sDM;
    sDM.GetData("Data/SpotifyFeatures - SpotifyFeatures.csv");
    vector<Song> dbSongs = sDM.getSongs();

    int genreCount = 0;

    for (int i = 0; i < dbSongs.size(); ++i)
    {
        if (dbSongs.at(i).getGenre()== genre)
        {
            ++genreCount;
            SongsByGenre.push_back(dbSongs.at(i));

            if (genreCount == 5) // songsByGenre now has 5 songs from a specific genre
            {
                break;
            }
        }
    }
}

void songsDataFilter :: getSongsByArtist(const string &artist) //select 5 songs from user's artist and add them to songsByArtist vector
{
    songsDataManager sDM;
    sDM.GetData("Data/SpotifyFeatures - SpotifyFeatures.csv");
    vector<Song> dbSongs = sDM.getSongs();

    int artistCount = 0;

    for (int i = 0; i < dbSongs.size(); ++i)
    {
        if (dbSongs.at(i).getArtist() == artist)
        {
            ++artistCount;
            SongsByArtist.push_back(dbSongs.at(i));

            if (artistCount == 5) // songsByArtist now has 5 songs from a specific artist
            {
                break;
            }
        }
    }
}

void songsDataFilter :: getSongsByMood(const string &mood)
{
    songsDataManager sDM;
    sDM.GetData("Data/SpotifyFeatures - SpotifyFeatures.csv");
    vector<Song> dbSongs = sDM.getSongs();

    int moodCount = 0;

    for (int i = 0; i < dbSongs.size(); ++i)
    {
        if (mood == "energetic" && dbSongs.at(i).getEnergyFactor() >= 0.8 && dbSongs.at(i).getEnergyFactor() <= 1.0)
        {
            ++moodCount;
            SongsByMood.push_back(dbSongs.at(i));

            if (moodCount == 5) // SongsByMood now has 5 songs from an energetic mood's energy range
            {
                break;
            }
        }
        else if (mood == "happy" && dbSongs.at(i).getEnergyFactor() >= 0.5 && dbSongs.at(i).getEnergyFactor() < 0.8)
        {
            ++moodCount;
            SongsByMood.push_back(dbSongs.at(i));

            if (moodCount == 5) // SongsByMood now has 5 songs from a happy mood's energy range
            {
                break;
            }
        }
        else if (mood == "tired" && dbSongs.at(i).getEnergyFactor() >= 0.2 && dbSongs.at(i).getEnergyFactor() < 0.5)
        {
            ++moodCount;
            SongsByMood.push_back(dbSongs.at(i));

            if (moodCount == 5) // SongsByMood now has 5 songs from a tired mood's energy range
            {
                break;
            }
        }
        else if (mood == "sad" && dbSongs.at(i).getEnergyFactor() >= 0 && dbSongs.at(i).getEnergyFactor() < 0.2)
        {
            ++moodCount;
            SongsByMood.push_back(dbSongs.at(i));

            if (moodCount == 5) // SongsByMood now has 5 songs from a sad mood's energy range
            {
                break;
            }
        }
        else
        {
            cout << "There are no songs available for that mood." << endl;
        }
    }
}

vector<Song> songsDataFilter :: personalizedSongList()
{
    vector<Song> tempSongsByGenre = SongsByGenre;

    SongsByGenre.insert(SongsByGenre.end(), SongsByArtist.begin(), SongsByArtist.end());
    SongsByGenre.insert(SongsByGenre.end(), SongsByMood.begin(), SongsByMood.end());

    personalizedSongs = SongsByGenre;
    SongsByGenre = tempSongsByGenre;

    return personalizedSongs;
} 