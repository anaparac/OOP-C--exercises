#include "game.h"

// Implementacija Game klase dolazi ovdje.

Game::Game(): mWindow(sf::VideoMode(500, 500), "Snake"), mSnake(10), mWorld(sf::Vector2i(500,500))
{
    //broj segmenata zmije po sekundi
    mTimePerFrame= mSnake.blocks_per_sec;


}

void Game::run()
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

void Game::processEvents()
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
    //dal mi ovaj dio treba?
            if (event.type == sf::Event::Closed)
                mWindow.close();
    }

}

void Game::update(sf::Time dt)
{
    if(mSnake.hasLost()) mSnake.reset();
    mSnake.update();
    mWorld.update(mSnake);
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mSnake);
    mWindow.draw(mWorld);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key code)
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

