#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "fairy.hpp"
#include "FlappyFairy.hpp"
#pragma once

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    
    SDL_Event e;

    bool check = false;
    bool quit = true;
    bool play = false;
    int delay = 20;
    bool create = true;

    int m_width;
    int m_height;

    int scrollingOffset = 0;
    bool intersected = false;

    SDL_Renderer *gRenderer = NULL;
    SDL_Texture *assets = NULL;

    //Mix_Music *bgm = NULL;
    Mix_Music *music = NULL;

public:

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
};

