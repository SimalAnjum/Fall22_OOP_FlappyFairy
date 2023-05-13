#include <SDL2/SDL.h>
#include <iostream>
#include "drawing.hpp"
#pragma once
using namespace std;

//This class handles the drawing functions & is also inherited by most of the other classes.
class Unit
{
protected:
    SDL_Rect srcRect, moverRect;

public:
    virtual void draw();
    virtual void fly() = 0; //pure virtual becuse this is how an object appers to moves on the screen and is different for every object.
    Unit();
    Unit(SDL_Rect a, SDL_Rect b);
    SDL_Rect* getMover(); //getter func that returns the moverrect that is then used to check for collisions.
    virtual ~Unit(); //virtual destructor
    void setMover(int xc, int yc); //setter func for mover
};
