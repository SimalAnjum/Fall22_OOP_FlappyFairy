#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "Unit.hpp"
#pragma once
using namespace std;

class bullet : public Unit
{
public:
    void fly();
    bullet(int x, int y);
    bullet();
    ~bullet();
};