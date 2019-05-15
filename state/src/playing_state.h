#ifndef PLAYING_STATE_H
#define PLAYING_STATE_H

#include "game.h"
#include "game_state.h"
#include "snake.h"
#include "world.h"

// Naša glavna state-klasa. Veći dio koda iz 
// prethodne Game klase završit će ovdje s manjim izmjenama.   
class PlayingState : public GameState{
public:
    PlayingState(Game *game);
    void run();

private:
    // Procesiraj događaje
    void processEvents();
    // konstruiraj novo stanje igre
    void update(sf::Time dt);
    // iscrtaj novo stanje
    void render();


    World mWorld;
    Snake mSnake;
    sf::Time mTimePerFrame;

    void handlePlayerInput(sf::Keyboard::Key code);
};


#endif // PLAYING_STATE_H

