#include <SDL2/SDL.h>
#include "Unit.hpp"
#pragma once

class fairy: public Unit
{
private:
    int obj_state = 0;
    //bool func for movement direction
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;

public:
    fairy();
    void handleEvent(SDL_Event &e); //this handles teh movement of the fairy in regards to the keys pressed

    ~fairy();
    void fly();
};