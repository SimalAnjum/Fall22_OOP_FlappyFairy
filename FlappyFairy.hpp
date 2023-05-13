#include<SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "fairy.hpp"
#include "Score.hpp"
#include "Score_h.hpp"
#include "coins.hpp"
#include "heart.hpp"
#include "Lives.hpp"
#include "bullet.hpp"
#include "spaceship.hpp"
#include "pipe.hpp"
#include "yoda.hpp"
#include "gamewon.hpp"
#include "gameover.hpp"

#include<vector>
#include<list>

using namespace std;

class ObjectCreator
{
public:
    Unit *getObject(); //factory method
    Unit *getCollectable(int n);
};


class FlappyFairy
{
    private:
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

    ObjectCreator obj;
    ObjectCreator col;

    bool Yoda=false;
    bool dotf=false;
    bool running = true;
    bool state= false;

    int life_count = 3;
    int score_count = 0;
    int j=10;
    
    Mix_Music* music=NULL;

    list<Unit *> hearts;
    list<Unit *> coin;
    list<Unit *> pipes;
    list<bullet *> bullets;
    list<lives*> lifelines;

    Score * scores = new Score();
    Score_h * health = new Score_h();
    spaceship * ss = new spaceship();
    yoda * baby = new yoda();


    public:
    fairy * fairy_few = new fairy();


    FlappyFairy();
    ~FlappyFairy();  //destructor to delete all ynamic objects
    void drawObjects(); 
    void createObject(int, int); //creates pipes object and pushes into list
    void createObject(); //creates life wala aik heart
    void drawScore(); //draws score which inc with inc in coins
    void bullet_spawn(); //spans a bullet with moverRect of spaceship
    void ss_spawn(); //spaceship appears on screen
    bool getstate(); //retuns true or false which then checks if fairy should move
    void gameend(); //decides which asset to draw depending on state.

};