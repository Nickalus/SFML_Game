#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "GameStateMachine.hpp"

class Game
{
  public: //Public member functions
    Game();

    //Run the game
    void Run();
  private: //Private member functions
    void ProcessEvents();
    void Update(sf::Time);
    void Draw(sf::RenderWindow&);
  private: //Private member variables
    sf::RenderWindow mWindow;
    const sf::Time mTimePerFrame;
    bool mIsPaused;
    GameStateMachine mStateMachine;
};

#endif
