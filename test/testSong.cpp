#include "../header/song.h"
#include "gtest/gtest.h"

#include <iostream>

using namespace std;

TEST (SongTest, testConstructor) {
    Song s("Heart Attack", "Pop", "Happy", "One Direction");
    EXPECT_EQ(s.getTitle(), "Heart Attack");
    EXPECT_EQ(s.getGenre(), "Pop");
    EXPECT_EQ(s.getMood(), "Happy");
    EXPECT_EQ(s.getArtist(), "One Direction");
    EXPECT_EQ(s.getRecommendation(), false);
}

TEST (SongTest, testChangeRecommendation) {
    Song s("Happiness is a butterfly", "Alternative", "Sad", "Lana Del Rey");
    s.changeRecommendation();
    EXPECT_EQ(s.getRecommendation(), true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}