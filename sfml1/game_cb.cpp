
#include "game_cb.h"

Game::Game(): mWindow(sf::VideoMode(400, 400), "SFML window")
{
    mUp = mDown = mLeft = mRight = false;
    mVelocity = 200;
    mDt= sf::seconds(1.0/60);

    if (!mTexture.loadFromFile("cb.bmp"))
        throw std::runtime_error("Cannot open file cb.bmp!");

     mSprite.setTexture(mTexture);

}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while( mWindow.isOpen()){
        //prvo procesiramo dogadaj
        //sf::Time dt = clock.restart();
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > mDt){
            processEvents();
            update(mDt);
            timeSinceLastUpdate -= mDt;
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
              handleUserInput(event.key.code, true);
           // if(event.key.code == sf::Keyboard::Up)
                break;
            case sf::Event::KeyReleased:
            //otpustena tipka
             handleUserInput(event.key.code, false);
                break;
        }

        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Game::update( sf::Time dt)
{
    sf::Vector2f movement(0, 0);

    if(mUp == true)    movement.y -= mVelocity;
    if(mDown == true)  movement.y += mVelocity;
    if(mLeft == true)  movement.x -= mVelocity;
    if(mRight == true) movement.x += mVelocity;

    //pomićemo u pixelima pomocu move(float, float)
    mSprite.move(movement*dt.asSeconds());
}

void Game::render()
{
    //ako nismo zatvorili prozor obavlja se iscrtavanje u buffer
    // Clear screen
    mWindow.clear();
    // Draw the sprite
    mWindow.draw(mSprite);
    // Update the window --- renderira ono iz buffera
    mWindow.display();
}

void Game::handleUserInput(sf::Keyboard::Key code, bool isPressed)
{
     if(code == sf::Keyboard::Up)
         mUp = isPressed;

     if(code == sf::Keyboard::Down)
         mDown = isPressed;

     if(code == sf::Keyboard::Left)
         mLeft = isPressed;

     if(code == sf::Keyboard::Right)
         mRight = isPressed;

}

