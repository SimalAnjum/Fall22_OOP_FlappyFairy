#include<SDL2/SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

class yoda : public Unit
{
    private:
    public:
        void fly(); // this will deal with the change in x and/or y coordinates.
        yoda(); // default constructor
        // int getx();
        // int gety();
        ~yoda();
};