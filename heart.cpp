#include "heart.hpp"
#include "drawing.hpp"

void heart::fly()
{
    srcRect = {774,173,58,60};
    moverRect.y = (moverRect.y+5);
}

heart::heart()
{
    srcRect = {774,173,58,60};

    moverRect = {30, 40, 50, 50};
}

heart::heart(SDL_Rect x, SDL_Rect y):Unit(x,y)
{

}

heart::~heart()
{
    
}

