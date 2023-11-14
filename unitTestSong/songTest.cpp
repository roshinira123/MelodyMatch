#include "gtest/gtest.h"

#include "../header/song.h"//header file

TEST(SongTest,songObj){
    //Song obj
    Song song1("ADO","Unravel",90,"J-Pop");

    //Expect
    EXPECT_EQ(song1.getArtist(),"ADO");
    EXPECT_EQ(song1.getName(),"Unravel");
    EXPECT_EQ(song1.getLength(),90);
    EXPECT_EQ(song1.getGenre(),"J-Pop");

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}