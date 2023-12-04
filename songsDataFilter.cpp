#include "songsDataFilter.h"

void songsDataFilter :: getSongsByGenre(const string &genre) //select 5 songs from user's genre and add them to songsByGenre vector
{
    songsDataManager sDM;
    vector<Song> dbSongs = sDM.getSongs();

    int genreCount = 0;

    for (int i = 0; i < dbSongs.size(); ++i)
    {
        if (dbSongs.at(i).getGenre().equals(genre))
        {
            ++genreCount;
            songsByGenre.push_back(dbSongs.at(i));

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
    vector<Song> dbSongs = sDM.getSongs();

    int artistCount = 0;

    for (int i = 0; i < dbSongs.size(); ++i)
    {
        if (dbSongs.at(i).getArtist().equals(artist))
        {
            ++artistCount;
            songsByArtist.push_back(dbSongs.at(i));

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
    vector<Song> tempSongsByGenre = songsByGenre;

    songsByGenre.insert(songsByGenre.end(), songsByArtist.begin(), songsByArtist.end());
    songsByGenre.insert(songsByGenre.end(), SongsByMood.begin(), SongsByMood.end());

    personalizedSongs = songsByGenre;
    songsByGenre = tempSongsByGenre;

    return personalizedSongs;
} 