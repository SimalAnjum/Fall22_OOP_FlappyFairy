#include "bullet.hpp"
#include "drawing.hpp"

void bullet::fly() //this is how much the bullet moves
{
    moverRect.x -= 10;
}

bullet::bullet()
{
    srcRect = {575, 53, 71, 10};
    moverRect = {10,10,50,8};
}

bullet::bullet(int x, int y) //overloaded constructer that initialises the x and y corodiates of the moverrect.
{
    srcRect = {575, 53, 71, 10};
    moverRect = {x,y,50,5};
}

bullet::~bullet()
{
    
}