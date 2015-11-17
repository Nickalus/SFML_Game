#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "GameStateMachine.hpp"

class Game
{
  public:
    Game();

    //Run the game
    void Run();

  private:
    void ProcessEvents();
    void Update(sf::Time);
    void Draw(sf::RenderWindow&);

  private:
    sf::RenderWindow mWindow;
    const sf::Time mTimePerFrame;
    bool mIsPaused;
    GameStateMachine mStateMachine;
};

#endif
