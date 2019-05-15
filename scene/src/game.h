#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "sceneGraph.h"


class Game{
public:
    Game();
    void run();

private:

    // Procesiraj događaje
    void processEvents();

    // konstruiraj novo stanje igre
    void update(sf::Time const &);

    // iscrtaj novo stanje
    void render();
private:
    // implementacijski detalji

    sf::RenderWindow mWindow;
    sf::Time mTimePerFrame;


    sf::Vector2i mLastMousePosition;
    SceneNode *backgd;
    PlaneNode *airplane;

    void handlePlayerInput( sf::Keyboard::Key code);
    void handleMouseInput();
};


#endif
