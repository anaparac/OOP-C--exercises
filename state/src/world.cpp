#include "world.h"
#include <ctime>
#include <random>

// Implementacija klase World dolazi ovdje.


World::World(sf::Vector2i windowSize)
{
    mWindowSize.x = windowSize.x;
    mWindowSize.y = windowSize.y;
    mBlockSize = 10;             // Veličina  bloka od kog je građena zmija
    mApple.setFillColor(sf::Color::Red);
    mApple.setPosition( mWindowSize.x/2, mWindowSize.y/2 );     // jabuka na pocetku na sredini
    mApple.setRadius((float)mBlockSize/2);

    mBounds[0].setFillColor(sf::Color::Magenta);
    mBounds[1].setFillColor(sf::Color::Magenta);
    mBounds[2].setFillColor(sf::Color::Magenta);
    mBounds[3].setFillColor(sf::Color::Magenta);

    // rubovi domene -> dim pravokutnika
    mBounds[0].setSize(sf::Vector2f(mWindowSize.x, mBlockSize));
    mBounds[1].setSize(sf::Vector2f(mBlockSize, mWindowSize.y));
    mBounds[2].setSize(sf::Vector2f(mWindowSize.x, mBlockSize));
    mBounds[3].setSize(sf::Vector2f(mBlockSize, mWindowSize.y));
    // rubovi domene -> pozicije gornjih lijevih vrhova pravokutnika
    mBounds[0].setPosition(0,0);
    mBounds[1].setPosition(0,0);
    mBounds[2].setPosition(0, mWindowSize.y - mBlockSize);
    mBounds[3].setPosition(mWindowSize.x - mBlockSize, 0);

}

void World::respawnApple()
{
    //odaberi random koordinate na ekranu (koje ne pripadaju rubu)
    sf::Vector2i nove_koord;
    nove_koord.x = (rand() % (mWindowSize.x - 2*mBlockSize)/mBlockSize + 1) * mBlockSize;
    nove_koord.y =( rand() % (mWindowSize.y - 2*mBlockSize)/mBlockSize + 1) * mBlockSize;

    //postavi pozicju jabuke
    mApple.setPosition(nove_koord.x, nove_koord.y);
}

void World::update(Snake &snake)
{
    //ako je udarila u zid -> ubi zmiju i zavrsi igru
    auto pozicija_glave = snake.getPosition();
    if(pozicija_glave.x < mBlockSize || pozicija_glave.y < mBlockSize || pozicija_glave.x >= mWindowSize.x - mBlockSize || pozicija_glave.y >= mWindowSize.y - mBlockSize ){
        //game_over
        snake.lose();
    }

    auto pozicija = snake.getPosition();
    //provjeri je li koordinata glave zmije na koordinati jabuke (jabuka je circle!)
    if(pozicija.x == mApple.getPosition().x && pozicija.y == mApple.getPosition().y){
        snake.extend();
        snake.increaseScore();
        respawnApple();
    }
}

//crtaj svijet
void World::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(int i=0; i<4; ++i)
      target.draw(mBounds[i]);
    target.draw(mApple);
}
