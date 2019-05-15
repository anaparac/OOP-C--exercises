#include "snake.h"
#include <iterator>

using namespace std;
//  Implementacija klase Snake dolazi ovdje.

Snake::Snake(int blockSize)
{
     msize = blockSize;      // Veličina jednog bloka zmije.
     mdir = Direction::None; // Trenutni smjer kretanja.
     mspeed = 4;     // Brzina zmije. (broj segmenata/sekunda)
     blocks_per_sec = sf::seconds(1.0/mspeed);
     mlives = 3;     // Broj preostalih života.
     mscore = 0;     // Postignuti bodovi.
     mlost = false;

     sf::Vector2i pozicijaglave;
     pozicijaglave.x = 100;
     pozicijaglave.y = 100;
     mSnakeBody.push_back(SnakeSegment(pozicijaglave.x, pozicijaglave.y) );
     mSnakeBody.push_back(SnakeSegment(pozicijaglave.x - msize, pozicijaglave.y ));
     mSnakeBody.push_back(SnakeSegment(pozicijaglave.x - 2*msize , pozicijaglave.y));
     mSnakeBody.push_back(SnakeSegment(pozicijaglave.x - 3*msize, pozicijaglave.y ));

     mbodyRect.setSize(sf::Vector2f(msize, msize));

}

Snake::~Snake()
{
    mSnakeBody.clear();
}

sf::Vector2i Snake::getPosition()
{
    return sf::Vector2i(mSnakeBody[0].x, mSnakeBody[0].y);
}

void Snake::extend()
{

    auto smjer = getDirection();
    //treamo koordinate zadnjeg elementa u vektoru
    auto zadnji = mSnakeBody[mSnakeBody.size() - 1];

    auto x = zadnji.x;
    auto y = zadnji.y;
    switch(smjer){
        case Direction::Up: mSnakeBody.push_back(SnakeSegment(x,y + msize)); break;
        case Direction::Down: mSnakeBody.push_back(SnakeSegment(x,y - msize)); break;
        case Direction::Left: mSnakeBody.push_back(SnakeSegment(x + msize,y)); break;
        case Direction::Right: mSnakeBody.push_back(SnakeSegment(x - msize,y)); break;
    }
}

void Snake::reset()
{
    mSnakeBody.clear();
    mdir = Direction::None;

    sf::Vector2i pozicijaglave;
    pozicijaglave.x = 100;
    pozicijaglave.y = 100;

    mSnakeBody.push_back(SnakeSegment(pozicijaglave.x, pozicijaglave.y) );
    mSnakeBody.push_back(SnakeSegment(pozicijaglave.x - msize, pozicijaglave.y ));
    mSnakeBody.push_back(SnakeSegment(pozicijaglave.x - 2*msize , pozicijaglave.y));
    mSnakeBody.push_back(SnakeSegment(pozicijaglave.x - 3*msize, pozicijaglave.y ));

    mspeed = 6;
    mlives = 3;
    mscore = 0;
    toggleLost();
}

void Snake::update()
{
   if(!mlives) lose();

   move();
   checkCollision();

}

void Snake::cut(int n)
{
    //odsjeci zadnjih n segmenata
    while(n){
        mSnakeBody.pop_back();
        n--;
    }
    //smanji broj života za 1
    mlives--;
}

void Snake::move()
{
    //pomakni zmiju za jedno mjesto u danom smjeru
    //pomakni glavu u tom smjeru a ostalima daj koordinate prethodnog segmenta

    auto smjer = getDirection();
    if(smjer != Direction::None){
        for(int i = mSnakeBody.size()-1; i > 0; i-- ){
            mSnakeBody[i].x = mSnakeBody[i-1].x;
            mSnakeBody[i].y = mSnakeBody[i-1].y;
    }

    auto glava = mSnakeBody[0];
    switch(smjer){

        case Direction::Up:
            mSnakeBody[0].y = glava.y - msize;
            break;
        case Direction::Down:
            mSnakeBody[0].y = glava.y + msize;
            break;
        case Direction::Left:
            mSnakeBody[0].x = glava.x - msize;
            break;
        case Direction::Right:
           mSnakeBody[0].x = glava.x + msize;
            break;
    }
}
}

void Snake::checkCollision()
{
    // Provjeri samopresjecanje i napravi odgovarajuću radnju.


    //pamti koliko blokova smo prosli da mozemo pozvat cut(n)
    int koliko = 0;
    for(int i = 1; i < mSnakeBody.size(); i++){
        koliko++;
        if(mSnakeBody[i].x == mSnakeBody[0].x && mSnakeBody[i].y == mSnakeBody[0].y )
            cut(mSnakeBody.size() - koliko);
     }
}

void Snake::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(auto i = mSnakeBody.begin(); i != mSnakeBody.end() ; ++i){
        if(i == mSnakeBody.begin()){
            mbodyRect.setFillColor(sf::Color::Yellow);
            mbodyRect.setOutlineColor(sf::Color::Black);
            mbodyRect.setOutlineThickness(1.0);
            mbodyRect.setPosition(i->x, i->y);
            target.draw(mbodyRect);
        }
        else{ mbodyRect.setFillColor(sf::Color::Green);
              mbodyRect.setPosition(i->x, i->y);
              mbodyRect.setOutlineColor(sf::Color::Black);
              mbodyRect.setOutlineThickness(1.0);
              target.draw(mbodyRect);

        }
    }


}
