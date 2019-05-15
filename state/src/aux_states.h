#ifndef AUX_STATES_H
#define AUX_STATES_H
#include <SFML/Graphics.hpp>
#include "game_state.h"

// Sva pomoćna stanja (osim PlayingState). Njihove implementacije
// su prilično slične pa ih možemo grupirati u jedan file. 

class WelcomeState : public GameState{
    public:
        WelcomeState(Game *game);
        void update(sf::Time dt);
        void handlePlayerInput(sf::Keyboard::Key code);
        void render();

    private:

        sf::Text text1;
        sf::Text text2;
        sf::Text text3;



};

class ExitingState : public GameState{
    public:
        ExitingState( Game *game );
        void update(sf::Time dt);
        void handlePlayerInput(sf::Keyboard::Key code);
        void render();

    private:

        sf::Text text1;
        //sf::Text text2;
        int brojac;

};

class WonState : public GameState{
    public:
        WonState(Game *game);
        void update(sf::Time dt);
        void handlePlayerInput(sf::Keyboard::Key code);
        void render();

    private:

        sf::Text text1;
        sf::Text text2;

};

class LostState : public GameState{
    public:
        LostState( Game *game );
        void update(sf::Time dt);
        void handlePlayerInput(sf::Keyboard::Key code);
        void render();

    private:

        sf::Text text1;
        sf::Text text2;

};

#endif // AUX_STATES_H
