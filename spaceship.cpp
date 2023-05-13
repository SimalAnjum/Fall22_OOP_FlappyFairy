#include "spaceship.hpp"
#include "drawing.hpp"

void spaceship::fly()
{
    srcRect = {740, 21, 111, 50};
    moverRect.y = (moverRect.y+1)%650;
}

spaceship::spaceship()
{
    srcRect = {740, 21, 111, 50};

    moverRect = {1100, 0, 100, 50};
}

spaceship::spaceship(int x, int y)
{
    srcRect = {740, 21, 111, 50};
    moverRect = {1100, 0, 100, 50};
}

int spaceship::getx()
{
    return moverRect.x;
}

int spaceship::gety()
{
    return moverRect.y;
}

spaceship::~spaceship()
{

}
