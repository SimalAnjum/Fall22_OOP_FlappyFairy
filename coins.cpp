#include "coins.hpp"
#include "drawing.hpp"

void coins::fly() //this is how the coin moves on the screen and is different for every object.
{
    if (obj_state == 0)
    {
        srcRect = {512,117,53,57};
    }
    else if (obj_state == 4)
    {
        srcRect = {570,117,47,58};
    }
    else if (obj_state == 8)
    {
        srcRect = {626,118,26,58};
    }
    else if (obj_state == 12)
    {
        srcRect = {537,185,9,57};
    }
    else if (obj_state == 16)
    {
        srcRect = {570,185,26,58};
    }
    else if (obj_state == 20)
    {
        srcRect = {608,184,46,58};
    }
    
    moverRect.y = (moverRect.y+5);
    
    if(obj_state>=24)
    {
        obj_state = 0;
    }
    else
    {
        obj_state += 1;
    }

}

coins::coins()
{
    srcRect = {512,117,53,57};

    moverRect = {0, 40, 50, 50};
}

coins::coins(SDL_Rect x, SDL_Rect y):Unit(x,y)
{

}

coins::~coins()
{
    
}