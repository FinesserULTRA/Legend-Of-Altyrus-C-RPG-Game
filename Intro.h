#pragma once
#include "Play.cpp"

struct Intro {
    void start();
    void newGamePlus(Player& player);
    void loadingScreen();
    void mainMenu();
    void options();
    void runCredits();
    void GameIntro();
    void fun();
    void CaC();

    bool playing = true;
    bool gameLoaded = false;
};