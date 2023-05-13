#include "pipe.hpp"
#include "drawing.hpp"

void pipe::fly()
{
    moverRect.x -= 5;
}

pipe::pipe()
{
    srcRect = {800, 304, 23, 321};
    moverRect = {10,10,20,200};
}

pipe::pipe(SDL_Rect a, SDL_Rect b): Unit(a, b)
{
}

pipe::~pipe()
{

}

