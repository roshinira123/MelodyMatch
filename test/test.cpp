#include <gtest/gtest.h>
#include "../header/songsDataManager.h"
#include "../header/song.h"
#include "../header/songsDataFilter.h"

using namespace std;

//Test if parsing is successful
TEST(SongDataTest, SuccessfulParsing) {
    songsDataManager s;
    s.GetData("Data/SpotifyFeatures - SpotifyFeatures.csv");
    vector<Song> songs = s.getSongs();

    ASSERT_FALSE(songs.empty()); // Ensure the list is not empty

    ASSERT_EQ(songs.at(0).getTitle(), "C'est beau de faire un Show");
    ASSERT_EQ(songs.at(0).getGenre(), "Movie");
}

//Test for invalid file path
TEST(SongDataTest, InvalidFilePath) {
    songsDataManager s;

    s.GetData("blahblahblah.csv");

    vector<Song> songs = s.getSongs();
    ASSERT_TRUE(songs.empty()); // Ensure the list is empty
}

//songsDataFilter.cpp tests
//Test for valid genre and five songs are generated
TEST(SongFilterTest, ValidGenreFiveSongs) {
    songsDataFilter f;

    f.getSongsByGenre("Pop");

    vector<Song> personalSongs = f.personalizedSongList();

    EXPECT_EQ(personalSongs.size(), 5);
}

//Test for invalid genre and zero songs are generated
TEST(SongFilterTest, InvalidGenreZeroSongs) {
    songsDataFilter f;

    f.getSongsByGenre("NotAGenre");

    vector<Song> personalSongs = f.personalizedSongList();

    EXPECT_EQ(personalSongs.size(), 0);
}

//Test for valid artist and five songs are generated
TEST(SongFilterTest, ValidArtistFiveSongs) {
    songsDataFilter f;

    f.getSongsByArtist("Britney Spears");

    vector<Song> personalSongs = f.personalizedSongList();

    EXPECT_EQ(personalSongs.size(), 5);
}

//Test for invalid artist and zero songs are generated
TEST(SongFilterTest, InvalidArtistZeroSongs) {
    songsDataFilter f;

    f.getSongsByArtist("NotAnArtist");

    vector<Song> personalSongs = f.personalizedSongList();

    EXPECT_EQ(personalSongs.size(), 0);
}

//Test for valid mood and five songs are generated
TEST(SongFilterTest, ValidMoodFiveSongs) {
    songsDataFilter f;

    f.getSongsByMood("happy");

    vector<Song> personalSongs = f.personalizedSongList();

    EXPECT_EQ(personalSongs.size(), 5);
}

//Test for invalid mood and zero songs are generated
TEST(SongFilterTest, InvalidMoodZeroSongs) {
    songsDataFilter f;

    f.getSongsByMood("NotAMood");

    vector<Song> personalSongs = f.personalizedSongList();

    EXPECT_EQ(personalSongs.size(), 0);
}

//Test for valid personalized song list
TEST(SongFilterTest, ValidSongList)
{
    songsDataFilter f;

    //songs from all categories
    f.getSongsByGenre("Movie");
    f.getSongsByArtist("Joji");
    f.getSongsByMood("energetic");

    vector<Song> personalSongs = f.personalizedSongList();
    EXPECT_EQ(personalSongs.size(), 15);  //5 songs from each category; 5 * 3 = 15 songs total
}

//Test for empty personalized song list and clear() function
TEST(SongFilterTest, InvalidSongListClear)
{
    songsDataFilter f;

    //songs from all categories
    f.getSongsByGenre("Dance");
    f.getSongsByArtist("Joji");
    f.getSongsByMood("tired");

    f.clear();

    //personalized song list with no songs
    vector<Song> personalSongs = f.personalizedSongList();
    EXPECT_EQ(personalSongs.size(), 0);
}

//Test that clear() function works
TEST(SongFilterTest, clearFunction)
{
    songsDataFilter f;

    //adding songs to filter
    f.getSongsByGenre("Alternative");
    f.getSongsByArtist("Jhene Aiko");
    f.getSongsByMood("wildcard");

    //clearing songs
    f.clear();

    vector<Song> personalSongs = f.personalizedSongList();

    EXPECT_EQ(personalSongs.size(), 0);
    EXPECT_EQ(personalSongs.size(), 0);
    EXPECT_EQ(personalSongs.size(), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}