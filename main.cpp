#include <iostream>
#include <string>
#include <vector>
#include "mainMenu.h"

int main() {
    mainMenu mm;

    mm.setGenres({"Pop", "Rock", "Jazz", "Blues"});
    mm.setMoods({"Upbeat", "Romantic", "Melancholic", "Angry"});
    mm.setArtists({"Artist 1", "Artist 2", "Artist 3", "Artist 4"});

    mm.getGenres();
    mm.getMoods();
    mm.getArtists();

    mm.suggestMusic();

    return 0;
}

