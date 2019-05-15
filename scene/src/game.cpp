#include "game.h"

// Implementacija klase Game.

Game::Game():mWindow( sf::VideoMode(700,700),  "Scene")
{
    mTimePerFrame = sf::seconds(1.0/60);
    backgd = new BackgrNode("../../../data/Desert.png");

    airplane = new PlaneNode("Prvi", "../../../data/Eagle.png", Plane_t::Eagle, sf::Vector2f(350.0, 350.0) );

    auto left_airplane = new PlaneNode("J","../../../data/Raptor.png", Plane_t::Raptor, sf::Vector2f( -70.0, 30.0));
    auto right_airplane = new PlaneNode("K", "../../../data/Raptor.png", Plane_t::Raptor, sf::Vector2f( 70.0, 30.0));

    right_airplane->addComponent(std::unique_ptr <SceneNode> (new PlaneNode("L","../../../data/Raptor.png", Plane_t::Raptor, sf::Vector2f( 70.0, 30.0 )) ));
    left_airplane->addComponent(std::unique_ptr <SceneNode> (new PlaneNode("H", "../../../data/Raptor.png", Plane_t::Raptor, sf::Vector2f( -70.0, 30.0)) ));

    airplane->addComponent(std::unique_ptr <SceneNode> (right_airplane) );
    airplane->addComponent(std::unique_ptr <SceneNode> (left_airplane) );

    mTimePerFrame = sf::seconds(1.0/60);
}


void Game::processEvents(){
    sf::Event event;
    while( mWindow.pollEvent(event) ){
        switch( event.type ){
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::KeyPressed:
                handlePlayerInput( event.key.code);
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left )
                    mLastMousePosition = sf::Mouse::getPosition(mWindow);
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left )
                    airplane->setVelocity(0.0,0.0);
                    break;
        }
    }
}


void Game::update(sf::Time const &time_){

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Vector2i mousePosition = sf::Mouse::getPosition(mWindow);
        sf::Vector2i delta = mLastMousePosition-mousePosition;
        // Ako se ne krecu samo po x osi odkomentiraj sljedecu liniju
        //delta.y=0;
        delta.x=delta.x;

        airplane->setVelocity(-(sf::Vector2f)delta);
        mLastMousePosition = mousePosition;
    }

    airplane->update(time_);
}


void Game::render(){
    mWindow.clear();
    mWindow.draw(*backgd);
    mWindow.draw(*airplane);
    mWindow.display();
}


void Game::run()
{

    sf::Clock clock;
    sf::Time time_Since_LastUpdate = sf::Time::Zero;

    while( mWindow.isOpen() ){

        while (clock.getElapsedTime() - time_Since_LastUpdate < mTimePerFrame)
        {
            processEvents();
        }
        time_Since_LastUpdate += mTimePerFrame;
        update(mTimePerFrame);
        render();
    }

}


void Game::handlePlayerInput(sf::Keyboard::Key code){
    switch (code) {
    case (sf::Keyboard::Key::H) :
            airplane->removeComponent("H");
            break;
    case (sf::Keyboard::Key::J) :
            airplane->removeComponent("J");
            break;
    case (sf::Keyboard::Key::K) :
            airplane->removeComponent("K");
            break;
    case (sf::Keyboard::Key::L) :
            airplane->removeComponent("L");
            break;
    case (sf::Keyboard::Key::Escape):
            mWindow.close();
    default:
        break;
    }
}


void Game::handleMouseInput(){
    sf::Vector2i mousePosition = sf::Mouse::getPosition(mWindow);
    sf::Vector2i delta = mLastMousePosition-mousePosition;
    mLastMousePosition = mousePosition;
}
