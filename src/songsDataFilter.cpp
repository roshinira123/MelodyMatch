#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include "../header/songsDataManager.h"
#include "../header/song.h"
#include "../header/songsDataFilter.h"

// Key:  /***/ at the end of a line means it was newly added

void songsDataFilter :: getSongsByGenre(const string &genre) //select 5 songs from user's genre and add them to songsByGenre vector
{
    songsDataManager sDM;
    sDM.GetData("Data/SpotifyFeatures - SpotifyFeatures.csv");
    vector<Song> dbSongs = sDM.getSongs();

    bool songOfGenreFound = true; /***/
    int genreCount = 0;

    for (int i = 0; i < dbSongs.size(); ++i)
    {
        if (dbSongs.at(i).getGenre() == genre)
        {
            songOfGenreFound = true; /***/
            ++genreCount;
            SongsByGenre.push_back(dbSongs.at(i));

            if (genreCount == 5) // songsByGenre now has 5 songs from a specific genre
            {
                break;
            }
        }
        else /***/
        {
            songOfGenreFound = false; /***/
        } /***/
    }

    if (songOfGenreFound == false) /***/
    {
        cout << endl; /***/
        cout << "We could not generate songs for the genre " << "\"" << genre << ".\"" << endl; /***/
    } /***/
}

void songsDataFilter :: getSongsByArtist(const string &artist) //select 5 songs from user's artist and add them to songsByArtist vector
{
    songsDataManager sDM;
    sDM.GetData("Data/SpotifyFeatures - SpotifyFeatures.csv");
    vector<Song> dbSongs = sDM.getSongs();

    bool songOfArtistFound = true; /***/
    int artistCount = 0;

    for (int i = 0; i < dbSongs.size(); ++i)
    {
        if (dbSongs.at(i).getArtist() == artist)
        {
            songOfArtistFound = true; /***/
            ++artistCount;
            SongsByArtist.push_back(dbSongs.at(i));

            if (artistCount == 5) // songsByArtist now has 5 songs from a specific artist
            {
                break;
            }
        }
        else /***/
        {
            songOfArtistFound = false; /***/
        } /***/
    }

    if (songOfArtistFound == false) /***/
    {
        cout << "We could not generate songs from the artist " << "\"" << artist << ".\"" << endl; /***/
    } /***/
}

void songsDataFilter :: getSongsByMood(const string &mood)
{
    songsDataManager sDM;
    sDM.GetData("Data/SpotifyFeatures - SpotifyFeatures.csv");
    vector<Song> dbSongs = sDM.getSongs();

    bool songOfMoodFound = true; /***/
    int moodCount = 0;

    for (int i = 0; i < dbSongs.size(); ++i)
    {
        if (dbSongs.at(i).getMood() == mood)
        {
            songOfMoodFound = true; /***/
            ++moodCount;
            SongsByMood.push_back(dbSongs.at(i));

            if (moodCount == 5)
            {
                break;
            }
        }
        else /***/
        {
            songOfMoodFound = false; /***/
        } /***/
    }

    if (songOfMoodFound == false) /***/
    {
        cout << "We could not generate songs for the mood " << "\"" << mood << ".\"" << endl; /***/
    } /***/
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

void songsDataFilter :: clear()
{
    SongsByGenre.clear();
    SongsByArtist.clear();
    SongsByMood.clear();
}