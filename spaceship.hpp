#include<SDL2/SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

class spaceship : public Unit
{
    private:
    public:
        void fly(); // this will deal with the change in x and/or y coordinates.
        spaceship(); // default constructor
        spaceship(int x, int y); // overloaded constructor that initialises the x and y values of moverrect with the passed values.
        int getx();//getter that returns x cord of moverRect
        int gety();//getter that returns y cord of moverRect
        ~spaceship();
};