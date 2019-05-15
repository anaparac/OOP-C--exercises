#include "game.h"


Game::Game(): mWindow(sf::VideoMode(700, 700), "SFML window")
{


    mDt= sf::seconds(1.0/60);

    //ucitamo slike iz u texture
    if (!sun.loadFromFile("SunRed.png"))
        throw std::runtime_error("Cannot open file SunRed.png!");
    if (!earth.loadFromFile("planet1.png"))
        throw std::runtime_error("Cannot open file planet1.png!");
    if (!plane.loadFromFile("Plane.png"))
        throw std::runtime_error("Cannot open file Plane.png!");

     //vektori za smanjivanje slika
     sf::Vector2f sunSize(140.0f, 140.0f);
     sf::Vector2f earthSize(70.0f, 70.0f);
     sf::Vector2f planeSize(50.0f, 35.0f);

     //sprite_sun
     mSprite_sun.setTexture(sun);
     mSprite_sun.setOrigin( (float)sun.getSize().x/2, (float)sun.getSize().y/2 );
     mSprite_sun.setScale( sunSize.x / mSprite_sun.getLocalBounds().width,
                           sunSize.y / mSprite_sun.getLocalBounds().height);
     mSprite_sun.setPosition(350, 350);     //centar sunca treba biti u centru prozora


     //sprite_earth
     mSprite_earth.setTexture(earth);
     mSprite_earth.setOrigin( (float)earth.getSize().x/2, (float)earth.getSize().y/2 );
     mSprite_earth.setScale( earthSize.x / mSprite_earth.getLocalBounds().width,
                             earthSize.y / mSprite_earth.getLocalBounds().height);


     mSprite_earth.setPosition(150, 150);
     mSprite_earth.setRotation(0);

     //sprite_plane
     mSprite_plane.setTexture(plane);
     mSprite_plane.setOrigin( (float)plane.getSize().x/2, (float)plane.getSize().y/2);
     mSprite_plane.setScale( planeSize.x / mSprite_plane.getLocalBounds().width,
                             planeSize.y / mSprite_plane.getLocalBounds().height);
     mSprite_plane.setPosition(150, 100);
     mSprite_plane.setRotation(0);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while( mWindow.isOpen()){
        //prvo procesiramo dogadaj

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

        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Game::update( sf::Time dt)
{
  //rotiramo Zemlju oko svoje osi
  mEarth_os_transform.rotate(1.2, mSprite_earth.getPosition());

  //rotiramo Zemlju oko Sunca
  auto pozicija_sunca = mSprite_sun.getPosition();
  mEarth_s_transform.rotate(0.1, pozicija_sunca);

  //komponira dvije transformacije
  e_transform = mEarth_s_transform * mEarth_os_transform;

  //avion oko Zemlje
  auto pozicija_zemlje = mSprite_earth.getPosition();
  mPlane_z_transform.rotate(3, pozicija_zemlje);

  //avion oko sunca
  auto pozicija_sunca1 = mSprite_sun.getPosition();
  mPlane_s_transform.rotate(0.1, pozicija_sunca1);

  //komponira dvije transformacije
  p_transform =  mPlane_s_transform * mPlane_z_transform;
}

void Game::render()
{
    //ako nismo zatvorili prozor obavlja se iscrtavanje u buffer
    // Clear screen
    mWindow.clear();
    // Draw the sprite
    mWindow.draw(mSprite_sun);
    mWindow.draw(mSprite_earth, e_transform);
    mWindow.draw(mSprite_plane, p_transform);
    // Update the window --- renderira ono iz buffera
    mWindow.display();
}





