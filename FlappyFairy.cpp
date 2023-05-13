#include <iostream>
#include "FlappyFairy.hpp"

Unit *ObjectCreator::getObject()
{
    int random, X_POS;
    Unit * u;
    random = rand() % 100;
    X_POS = 1200 + (rand() % 100);
    if (random<33)
    {
        SDL_Rect a = {678, 365, 23, 260};
        SDL_Rect b = {X_POS,200,50,400};
        Unit * u = new pipe(a,b);
        return u;
    }

    else if (random>66)
    {
        SDL_Rect a = {800, 304, 23, 321};
        SDL_Rect b = {X_POS,350,50,300};
        Unit * u = new pipe(a,b);
        return u;
    }
    else
    {
        SDL_Rect a= {548, 479, 24, 143};
        SDL_Rect b = {X_POS,100,50,150}; 
        Unit * u = new pipe(a,b);
        return u;
    }
    return u;
}

Unit *ObjectCreator::getCollectable(int n)
{
    int random, x_pos;
    Unit * u;
    x_pos = rand() % 1200;

    if (n==1)
    {
        SDL_Rect a = {774,173,58,60};
        SDL_Rect b = {x_pos, 0, 50, 50};
        Unit * u = new heart(a,b);
        return u;
    }

    else
    {
        SDL_Rect a = {678, 365, 23, 260};
        SDL_Rect b = {x_pos, 0, 50, 50};
        Unit * u = new coins(a,b);
        return u;
    }
    return u;
}


void FlappyFairy::drawObjects()
{
    //drawLife();
    drawScore();
    ss_spawn();
    health->draw();
    
    int prob;
    prob = (rand()%500)+1;
    if (prob==1)
    {
        bullet_spawn();
    }

    if (dotf==false)
    {
        fairy_few ->draw();
        //yoda is initialised at random coordinates.
        static const int rand_x = rand()%1000;
        static const int rand_y = rand()%500;
        baby->setMover(rand_x,rand_y);
        baby->draw();

        for(lives* l:lifelines)
        {  
            l->draw();
        }
        
        drawScore();
        health->draw();

    }


    if(SDL_HasIntersection(baby->getMover(), fairy_few->getMover()))
        {
            fairy_few->setMover(0,0); //after collision fairy ki position is chnaged to (0,0)
            if (score_count>=5)
            {
                running = false;
                state = true;
            }
            else
            {
                running=true;
                state=false;
            }
            
        }

    if (life_count==0)
    {
        running = false;
    }

    if (life_count>3)
    {
        life_count=3;
    }

    for(Unit* p: pipes)
    {  
        p->draw();
    }

    for(Unit* h:hearts)
    {  
        h->draw();
    }

    for(bullet*& b: bullets)
    {   
        b->draw();       
    }

    for(Unit* c:coin)
    {  
        c->draw();
    }

    for(Unit* c: coin)
    {
        if(SDL_HasIntersection(c->getMover(), fairy_few->getMover()))
        {
            c->setMover(0,700); //h ka mover set karo not fairy idhr and change bool_screen to true takay remove krlo :)
            score_count +=1;
            music=Mix_LoadMUS("coin.wav");
			Mix_PlayMusic(music,0);
            //yahan pr change score after checking conditions.
            //scores= scores+1;
            scores->setter(score_count); //setter func for which srcRect score to draw
            //scores->setter(scores)
            drawScore();
            cout<<"YAY!"<<endl;
        }
        else
        {
            cout <<"NO"<<endl;
        }

    }

    for(Unit* h: hearts)
    {
        if(SDL_HasIntersection(h->getMover(), fairy_few->getMover()))
        {
            h->setMover(0,0); //h ka mover set karo not fairy idhr and change bool_screen to true takay remove krlo :)
            life_count +=1;
            //health+=1;
            health->setter(life_count);
            health->draw();
            music=Mix_LoadMUS("inc.wav");
			Mix_PlayMusic(music,0);

            cout<<"YAY!"<<endl;
        }

        else
        {
            cout<<"nope"<<endl;
        }
    }

    for(Unit* p: pipes)
    {
        if(SDL_HasIntersection(p->getMover(), fairy_few->getMover())) //checks for collison between pipes and fairy.
        {
            fairy_few->setMover(0,0);
            life_count -=1;
            music=Mix_LoadMUS("minuslife.wav");//collison sounf effect
			Mix_PlayMusic(music,0);
            health->setter(life_count);
            health->draw();
            cout<<"WHOOOOOOOOOOOPS"<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
    }

    for(bullet*& b: bullets)
    {
        if(SDL_HasIntersection(b->getMover(), fairy_few->getMover()))
        {
            fairy_few->setMover(0,0);
            b->setMover(0,700);
            life_count -=2;
            music=Mix_LoadMUS("minuslife.wav");
			Mix_PlayMusic(music,0);
            //yahan pr make changes to num of lives
            health->setter(life_count);
            health->draw();
            cout<<"WHOOPS"<<endl;
        }
        else
        {
            cout<<"bull"<<endl;
        }
     
    }

}

void FlappyFairy::createObject(int x, int y)
{
    int ran;
    ran= rand()%100;

    if (ran%2==0)
    {
        pipes.push_back(obj.getObject());
    }

    if (ran%11==0)
    {
        coin.push_back(col.getCollectable(2));
    }

    if (ran%5==0)
    {
        hearts.push_back(col.getCollectable(1));
    }
    else
    {
        cout << "hello world!"<<endl;
    }

}

void FlappyFairy::createObject()
{
    lives* l1= new lives(1);

    lifelines.push_back(l1);


}

void FlappyFairy::drawScore()
{ 
    scores->draw(); 
}


void FlappyFairy::ss_spawn()
{
    ss->draw();
}

void FlappyFairy::bullet_spawn()
{
    bullet * bullet1 = new bullet(ss->getx(),ss->gety());
    bullets.push_back(bullet1);
}

FlappyFairy::~FlappyFairy() //deletes dynamic objects
{
    fairy_few = NULL;
    delete fairy_few;

    baby = NULL;
    delete baby;

    ss = NULL;
    delete ss;

    scores = NULL;
    delete scores;

    Mix_FreeMusic(music);
    music = NULL;
    
    Mix_Quit();

    for (list<Unit *>::iterator i = hearts.begin(); i != hearts.end(); i++)
    {
        delete (*i);
        hearts.erase(i);
    }

    for (list<Unit *>::iterator i = coin.begin(); i != coin.end(); i++)
    {
        delete (*i);
        coin.erase(i);
    }

    for (list<Unit *>::iterator i = pipes.begin(); i != pipes.end(); i++)
    {
        delete (*i);
        pipes.erase(i);
    }

    for (list<bullet *>::iterator i = bullets.begin(); i != bullets.end(); i++)
    {
        delete (*i);
        bullets.erase(i);
    }

    for (list<lives *>::iterator i = lifelines.begin(); i != lifelines.end(); i++)
    {
        delete (*i);
        lifelines.erase(i);
    }

}


FlappyFairy::FlappyFairy()
{
    
}

bool FlappyFairy::getstate() //gets game state to check if fairy should move or not.
{
    if (running == true)
    {
        return false;
    }
    else
    {
        return true;
    }

}

void FlappyFairy::gameend() //conditions fro the end of game
{
    if (running == false && state == true)
    {
        // music=Mix_LoadMUS("won.wav");
		// Mix_PlayMusic(music,0);
        gamewon * won = new gamewon();
        won->draw();
    }

    else if (running == false && state == false)
    {
        // music=Mix_LoadMUS("lost.wav");
		// Mix_PlayMusic(music,-1);        
        gameover * lost = new gameover();
        lost->draw();
    }
}
