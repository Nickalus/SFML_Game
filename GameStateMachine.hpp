/*
 * State machine that handles the changing and adding of new states
 * */

#include <queue>

#include "GameState.hpp"

class GameStateMachine
{
  public:
    GameStateMachine();
    ~GameStateMachine();

    void Update(sf::Time);
    void Draw(sf::RenderWindow&);

    bool Push(GameState *);
    bool Change(GameState *);
    void Pop();
  private:
    std::queue<GameState*> mGameStates;
};
