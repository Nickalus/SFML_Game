/*
 * State machine that handles the changing and adding of new states
 * */
 
#include <queue>

#include "gamestate.hpp"

class GameStateMachine
{
  public:
    GameStateMachine();
    ~GameStateMachine();
    
    void Update();
    void Draw();
    
    bool Push(GameState *);
    bool Change(GameState *);
    void Pop();
  private:
    std::queue<GameState*> mGameStates;
};
