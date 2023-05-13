#include "Score_h.hpp"
#include "drawing.hpp"

void  Score_h :: operator+(int n)
{

    if (value<3)
    {
        value = value +n;
    }

    else
    {
        value = 3;
    }

}

void Score_h :: setter(int n)
{
    value=n;
}

void Score_h ::fly()
{
    moverRect = {125, 500, 50, 50};

    if (value==0)
    {
        srcRect={408,766,31,36};
    }

    if (value==1)
    {
        srcRect={482,767,27,34};
    }

    if (value==2)
    {
        srcRect={551,767,28,34};
    }

    if (value>=3)
    {
        value=3;
        srcRect={623,767,27,34};
    }

}


Score_h ::Score_h()
{
    srcRect={408,766,31,36};
    moverRect = {125, 500, 50, 50};
}

Score_h ::~Score_h()
{
    
}
