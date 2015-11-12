#include "GameStateMachine.hpp"

GameStateMachine::GameStateMachine()
{
}

GameStateMachine::~GameStateMachine()
{
}

void GameStateMachine::Update()
{
  if(!mGameStates.empty())
  {
    mGameStates.back()->Update();
  }
}

void GameStateMachine::Draw()
{
  if(!mGameStates.empty())
  {
    mGameStates.back()->Draw();
  }
}

bool GameStateMachine::Push(GameState * state)
{
  mGameStates.push(state);
  
  mGameStates.back()->Init();
}

bool GameStateMachine::Change(GameState * state)
{
  if(!mGameStates.empty())
  {
    if(mGameStates.back()->getStateID() == state->getStateID())
    {
      return; //do nothing
    }
    else
    {
      //Exit the state and pop it off the stack
      mGameStates.back()->Exit();
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
