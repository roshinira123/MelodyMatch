#include "songsDataFilter.h"

void addSongsByGenre(vector<string> &songsByGenre, vector<string> songsTitles, vector<string> &personalizedSongs, string genre) //select 5 songs from user's genre and add them to songsByGenre vector
{
    int genreCount = 0;

    for (int i = 0; i < songsByGenre.size(); ++i)
    {
        if (songsByGenre.at(i).equals(genre))
        {
            ++genreCount;
        }
    }

    if (genreCount >= 1)
    {
        for (int j = i; j < genreCount - 1; ++j)
        {
            personalizedSongs.push_back(songsTitles.at(j));
        }
    }
}

void addSongsByArtist(vector<string> &songsByArtist, vector<string> songsTitles, vector<string> &personalizedSongs, string artist)
{
    int artistCount = 0;

    for (int i = 0; i < songsByArtist.size(); ++i)
    {
        if (songsByArtist.at(i).equals(artist))
        {
            ++artistCount;
        }
    }

    if (artistCount >= 1)
    {
        for (int j = i; j < artistCount - 1; ++j)
        {
            personalizedSongs.push_back(songsTitles.at(j));
        }
    }
}

void addSongsByMood(vector<string> &songsByEnergy, vector<string> songsTitles, vector<string> &personalizedSongs, string mood)
{
    if (mood.equals("energetic") || mood.equals("happy"))
    {
        for (int i = 0; i < songsByEnergy.size(); ++i)
        {
            if (songsByEnergy.at(i) >= 0.5 && songsByEnergy.at(i) <= 1.0)
            {
                personalizedSongs.push_back(songsByEnergy.at(i));
            }
        }
    }

    if (mood.equals("tired") || mood.equals("sad"))
    {
        for (int i = 0; i < songsByEnergy.size(); ++i)
        {
            if (songsByEnergy.at(i) >= 0 && songsByEnergy.at(i) < 0.5)
            {
                personalizedSongs.push_back(songsByEnergy.at(i));
            }
        }
    }
}