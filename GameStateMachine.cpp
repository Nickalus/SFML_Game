#include "GameStateMachine.hpp"

GameStateMachine::GameStateMachine()
{
}

GameStateMachine::~GameStateMachine()
{
}

void GameStateMachine::Update(sf::Time time)
{
  if(!mGameStates.empty())
  {
    mGameStates.top()->Update(time);
  }
}

void GameStateMachine::Draw(sf::RenderWindow& window)
{
  if(!mGameStates.empty())
  {
    mGameStates.top()->Draw(window);
  }
}

bool GameStateMachine::Push(GameState * state)
{
  mGameStates.push(state);

  mGameStates.top()->Init();
}

bool GameStateMachine::Change(GameState * state)
{
  if(!mGameStates.empty())
  {
    if(mGameStates.top()->getStateID() == state->getStateID())
    {
      return; //do nothing
    }
    else
    {
      //Exit the state and pop it off the stack
      mGameStates.top()->Exit();
      mGameStates.pop();
    }
  }

  //initialise it
  state->Init();

  //push back our new state
  mGameStates.push(state);
}

void GameStateMachine::Pop()
{
  if(!mGameStates.empty())
  {
    mGameStates.back()->Exit();
    mGameStates.pop();
  }

  mGameStates.back()->Resume();
}
