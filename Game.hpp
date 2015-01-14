#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "Player.hpp"

class Game
{
  public: //Public member functions
    Game();
    
    void Run();
  private: //Private member functions
    void ProcessEvents();
    void Update(sf::Time);
    void Draw();
  private: //Private member variables
    sf::RenderWindow mWindow;
    const mTimePerFrame;
    
    Player mPlayer;
};

#endif
