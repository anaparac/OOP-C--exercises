#include "aux_states.h"
#include "game.h"
#include <unistd.h>
#include <string>

// Implementacija pomoćnih stanja.

//WELCOME

WelcomeState::WelcomeState(Game *game):GameState(game)
{
    // select the font
        text1.setFont(game->font1);
        text2.setFont(game->font2);
        text3.setFont(game->font2);

        // set the string to display
        text1.setString("SNAKE GAME");
        text3.setString("by Ana ");
        text2.setString("Press any key to start game");

        // set the character size
        text1.setCharacterSize(24);
        text2.setCharacterSize(14);
        text3.setCharacterSize(16);

        // set the color
        text1.setColor(sf::Color::Blue);
        text2.setColor(sf::Color::White);
        text2.setColor(sf::Color::White);



        //set origin -> namjestiti da se ispise u sredinu ekrana


        //set position
        text1.setPosition(sf::Vector2f(mpGame->mSize/2.0 - 140, mpGame->mSize/2.0 - 100));
        text2.setPosition( mpGame->mSize/2.0, mpGame->mSize/2.0 +200);
        text3.setPosition(sf::Vector2f(mpGame->mSize/2.0 - 100, mpGame->mSize/2.0 - 50));


}

void WelcomeState::update(sf::Time dt)
{}

void WelcomeState::handlePlayerInput(sf::Keyboard::Key code)
{
    //ako je pritisnuo bilo sto prebaci ga na igru
    mpGame->changeState(GameState::Playing);

}

void WelcomeState::render()
{
    mpGame->mWindow.draw(text1);
    mpGame->mWindow.draw(text3);
    mpGame->mWindow.draw(text2);
}

//EXITING

ExitingState::ExitingState(Game *game):GameState(game)
{
    brojac = 3;
    text1.setFont(game->font1);
    std::string text_za_ispis = "GAME OVER  " + std::to_string(brojac);
       text1.setString(text_za_ispis);
       text1.setCharacterSize(24);
       text1.setColor(sf::Color::Yellow);
       text1.setPosition(sf::Vector2f(mpGame->mSize/2.0 - 140, mpGame->mSize/2.0 - 10));
}

void ExitingState::update(sf::Time dt)
{
        static sf::Clock clock;
        static sf::Time LastUpdate = sf::Time::Zero;

        const sf::Time dt_ = sf::milliseconds(1000);
        if (  dt_ > LastUpdate ){
            LastUpdate += clock.getElapsedTime();
            return;
        }
        if ( brojac > 0 ){
            sleep(1);
            brojac--;
            std::string text_za_ispis = "GAME OVER " + std::to_string(brojac);
            text1.setString(text_za_ispis);
            LastUpdate = sf::Time::Zero;
            clock.restart();
        }
        else    //zatvori prozor
            exit(0);
}

void ExitingState::handlePlayerInput(sf::Keyboard::Key code)
{
    //nema inputa
}

void ExitingState::render()
{
    mpGame->mWindow.draw(text1);
}

//WON


WonState::WonState(Game *game):GameState(game)
{
    std::string text_za_ispis = "CONGRATULATIONS! \n YOU WON   \nSCORE  " + std::to_string(mpGame->mScore);
    text1.setFont(game->font1);
    text1.setString(text_za_ispis);
    text1.setCharacterSize(16);
    text1.setColor(sf::Color::White);
    text1.setPosition(sf::Vector2f(mpGame->mSize/2.0 - 140, mpGame->mSize/2.0 - 110));
    text2.setFont(game->font2);
    text2.setString("Hit C to continue or X to exit");
    text2.setCharacterSize(14);
    text2.setPosition( mpGame->mSize/2.0, mpGame->mSize/2.0 +200);
}

void WonState::update(sf::Time dt)
{
    text1.setString("CONGRATULATIONS! \n YOU WON   \nSCORE  " + std::to_string(mpGame->mScore));
}

void WonState::handlePlayerInput(sf::Keyboard::Key code)
{
    switch( code ){
        case sf::Keyboard::Key::C:
            mpGame->changeState(GameState::Playing);
            break;
        case sf::Keyboard::Key::X:
            mpGame->changeState(GameState::Exiting);
        break;

    }
}

void WonState::render()
{
    mpGame->mWindow.draw(text1);
    mpGame->mWindow.draw(text2);
}

//LOST

LostState::LostState(Game *game):GameState(game)
{

       std::string text_za_ispis = " YOU LOST \n SCORE  " + std::to_string(mpGame->mScore);
       text1.setFont( game->font1 );
       text1.setString(text_za_ispis);
       text1.setCharacterSize(16);
       text1.setColor(sf::Color::Yellow);
       text1.setPosition(sf::Vector2f(mpGame->mSize/2.0 - 120, mpGame->mSize/2.0 - 110));


       text2.setFont( game->font2);
       text2.setString("Hit C to continue or X to exit");
       text2.setCharacterSize(14);
       text2.setPosition( mpGame->mSize/2.0, mpGame->mSize/2.0 +200);

}

void LostState::update(sf::Time dt)
{
    text1.setString(" YOU LOST \n SCORE  " + std::to_string(mpGame->mScore));
}

void LostState::handlePlayerInput(sf::Keyboard::Key code)
{
    switch( code ){
        case sf::Keyboard::Key::C:
            mpGame->changeState(GameState::Playing);
            break;
        case sf::Keyboard::Key::X:
            mpGame->changeState(GameState::Exiting);
        break;

    }
}

void LostState::render()
{
    mpGame->mWindow.draw(text1);
    mpGame->mWindow.draw(text2);
}
