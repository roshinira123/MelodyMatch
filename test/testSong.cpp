#include "../header/song.h"
#include "gtest/gtest.h"

#include <iostream>

using namespace std;

TEST (SongTest, testConstructor) {
    Song s("Heart Attack", "Pop", "Happy", "One Direction", "5zsYl9Nl4kQmPSjwscVASJ", 0.98, 0.7, 0.6);
    EXPECT_EQ(s.getTitle(), "Heart Attack");
    EXPECT_EQ(s.getGenre(), "Pop");
    EXPECT_EQ(s.getMood(), "Happy");
    EXPECT_EQ(s.getArtist(), "One Direction");
    EXPECT_EQ(s.getTrackID(), "https://open.spotify.com/track/5zsYl9Nl4kQmPSjwscVASJ");
    EXPECT_DOUBLE_EQ(s.getDancebilityFactor(), 0.98); 
    EXPECT_DOUBLE_EQ(s.getEnergyFactor(), 0.7); 
    EXPECT_DOUBLE_EQ(s.getLivenessFactor(), 0.6);
    EXPECT_EQ(s.getRecommendation(), false);
}

TEST (SongTest, testChangeRecommendation) {
    Song s("Happiness is a butterfly", "Alternative", "Sad", "Lana Del Rey", "3lG6OtGDsYAOALxEmubQQm", 0.7, 0.6, 0.45);
    s.changeRecommendation();
    EXPECT_EQ(s.getRecommendation(), true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}