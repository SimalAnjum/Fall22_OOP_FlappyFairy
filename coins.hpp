#include<SDL2/SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

class coins : public Unit
{
    private:
        int obj_state = 0; // the object has 3 different states this will be updates continuosly to represent them.
        bool fall = true;
    
    public:
        void fly(); // this will deal with the change in x and/or y coordinates.
        coins(); // default constructor
        coins(SDL_Rect x, SDL_Rect y); // overloaded constructor that initialises the x and y values of moverrect with the passed values.
        ~coins();
};