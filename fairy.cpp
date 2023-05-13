#include "fairy.hpp"
#include <iostream>

using namespace std;

void fairy::fly()
{
    if (obj_state == 0)
    {
        srcRect = {25, 60, 94, 121};
    }
    else if (obj_state == 4)
    {
        srcRect = {297, 62, 98, 107};
    }
    else if (obj_state == 8)
    {
        srcRect = {7, 265, 110, 87};
    }
    else if (obj_state == 12)
    {
        srcRect = {305, 250, 99, 98};
    }
    else if (obj_state == 16)
    {
        srcRect = {10, 459, 95, 101};
    }
    else if (obj_state == 20)
    {
        srcRect = {301, 458, 81, 97};
        obj_state = -1;
    }

    obj_state++;
}


fairy::fairy()
{
    srcRect = {25, 60, 94, 121};
    moverRect = {0, 300, 75, 50};
}


void fairy::handleEvent(SDL_Event &e)
{
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) //tracks which key is pressed
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            up = true;
            cout << "up" << endl;
            break;
        case SDLK_DOWN:
            down = true;
            cout << "down" << endl;

            break;
        case SDLK_LEFT:
            cout << "left" << endl;
            left = true;
            break;
        case SDLK_RIGHT:
            right = true;
            cout << "right" << endl;
            break;
        }
    }
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            up = false;
            break;
        case SDLK_DOWN:
            down = false;
            break;
        case SDLK_LEFT:
            left = false;

            break;
        case SDLK_RIGHT:
            right = false;
            break;
        }
    }
    if (right) //chnage in coords wrt keys.
    {
        moverRect.x += 15;
    }
    if (left)
    {
        moverRect.x -= 15;
    }

    if (up)
    {
        moverRect.y -= 15;
    }
    if (down)
    {
        moverRect.y += 15;
    }

    if (moverRect.x <= 0)
    {
        moverRect.x = 0;
    }

    else if (moverRect.x >= 1200)
    {
        moverRect.x = 0;
    }

    if (moverRect.y < 0)
    {
        moverRect.y = 600;
    }

    else if (moverRect.y > 600)
    {
        moverRect.y = 0;
    }
}

fairy::~fairy()
{

}
