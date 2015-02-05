#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "GameStateMachine.hpp"

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
    
    GameStateMachine* mpGameStateMachine;
};

#endif
