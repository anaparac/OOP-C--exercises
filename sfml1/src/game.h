#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>


class Game{
public:
    Game();
    void run();

private:
    sf::RenderWindow mWindow;
    sf::Texture      sun;
    sf::Texture      earth;
    sf::Texture      plane;
    sf::Sprite       mSprite_sun;
    sf::Sprite       mSprite_earth;
    sf::Sprite       mSprite_plane;
    sf::Transform mEarth_os_transform;
    sf::Transform mPlane_z_transform;
    sf::Transform mEarth_s_transform;
    sf::Transform mPlane_s_transform;

    sf::Transform p_transform;
    sf::Transform e_transform;


//    float mVelocity;
    sf::Time mDt;
    void processEvents();
    void update(sf::Time dt);
    void render();



};

#endif // GAME_H

