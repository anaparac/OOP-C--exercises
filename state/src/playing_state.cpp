#include "playing_state.h"
#include <string.h>

// Implementacija PlayingState klase

PlayingState::PlayingState(Game *game): GameState( game ), mSnake(10), mWorld(sf::Vector2i(500,500))
{
    //broj segmenata zmije po sekundi
    mTimePerFrame= mSnake.blocks_per_sec;


}

/*
void PlayingState::run()
{
    sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        while( mWindow.isOpen()){
            //prvo procesiramo dogadaj

            processEvents();
            timeSinceLastUpdate += clock.restart();
            while(timeSinceLastUpdate > mTimePerFrame){
                processEvents();
                update(mTimePerFrame);
                timeSinceLastUpdate -= mTimePerFrame;
            }

            render();
    }
}
*/
/*
void PlayingState::processEvents()
{
    sf::Event event;
        while(mWindow.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    mWindow.close();
                    break;
                case sf::Event::KeyPressed:
                //stisnuta tipka Up
                  handlePlayerInput(event.key.code);
                    break;
            }

    }

}
*/


void PlayingState::update(sf::Time dt)
{
    mSnake.update();
    mWorld.update(mSnake);
    if(mSnake.hasLost() || !mSnake.getLives()) {
        mpGame->mScore = mSnake.getScore();
        if(mpGame->mScore < 100)
            mpGame->changeState(GameState::Lost);
        else
            mpGame->changeState(GameState::Won);

        //resetiraj igru
        mSnake.reset();
        mSnake.toggleLost();
        mWorld.respawnApple();
        //ako je igrac pobjedio -> povecaj brzinu
        if(mpGame->mScore >= 100)
            mSnake.speedUp();
    }


}

void PlayingState::render()
{
    mpGame->mWindow.draw(mSnake);
    mpGame->mWindow.draw(mWorld);
}

void PlayingState::handlePlayerInput(sf::Keyboard::Key code)
{
         if(code == sf::Keyboard::Up && mSnake.getDirection() != Direction::Down)
             mSnake.setDirection(Direction::Up);

         if(code == sf::Keyboard::Down && mSnake.getDirection() != Direction::Up)
             mSnake.setDirection(Direction::Down);

         if(code == sf::Keyboard::Left && mSnake.getDirection() != Direction::Right && mSnake.getDirection() != Direction::None)
              mSnake.setDirection(Direction::Left);

         if(code == sf::Keyboard::Right && mSnake.getDirection() != Direction::Left)
             mSnake.setDirection(Direction::Right);

}

