#include "Score.hpp"
#include "drawing.hpp"

Score Score:: operator+(int n)
{
    
    Score sc;

    if (value<5)
    {
        sc.value = value +n;
    }

    else
    {
        sc.value = value;
    }

    return sc;
}

void Score:: setter(int n)
{
    value=n;
}

void Score::fly()
{
    moverRect = {80, 425, 50, 50};

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

    if (value==3)
    {
        srcRect={623,767,27,34};
    }

    if (value==4)
    {
        srcRect={694,767,29,34};
    }

    if (value>=5)
    {
        srcRect={768,767,27,34};
    }

}


Score::Score()
{
    srcRect={408,766,31,36};
    moverRect = {80, 425, 50, 50};
}

Score::~Score()
{
    
}
