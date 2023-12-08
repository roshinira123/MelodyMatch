#ifndef MAINMENU_H
#define MAINMENU_H


#include <iostream>
#include <string>
#include <vector>
#include "../header/songsDataFilter.h"
#include "../header/loginAuth.h"



class mainMenu {
private:
   
public:
    mainMenu();
    void displayMainMenu();
    void displayMusicOptions();
    void personalizeSongs();
    void LoginHandler();
};


#endif