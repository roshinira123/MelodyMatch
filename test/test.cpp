#include <gtest/gtest.h>
#include "../header/songsDataManager.h"
#include "../header/song.h"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}