#ifndef GAMESTATEMACHINE_HPP
#define GAMESTATEMACHINE_HPP

#include <stack>
#include "GameState.h"

class GameStateMachine
{
  public:
    GameStateMachine()
    ~GameStateMachine()
    
    void HandleEvents(const sf::Event&);
    void Update(sf::Time);
    void Draw(sf::RenderWindow&);
    
    void PushState(GameState*);
    void ChangeState(GameState*);
    void PopState();
    
    void Clean();
  private:
    std::stack<GameState*> mGameStates;
};

#endif
