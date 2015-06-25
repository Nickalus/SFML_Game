#include "GameStateManager.hpp"
#include <iostream>

// Global static pointer used to ensure a single instance of the class.
GameStateManager* GameStateManager::mpInstance = nullptr;

//This class is a singleton to avoid passing it around
GameStateManager* GameStateManager::Instance()
{
  if(!mpInstance)   //Only allow one instance of class to be generated.
  {
    mpInstance = new GameStateManager;
  }

  return mpInstance;
}

void GameStateManager::ProcessEvents(const sf::Event& event)
{
    mStateStack.top()->ProcessEvents(event);
}

void GameStateManager::Update(sf::Time dt)
{
  mStateStack.top()->Update(dt);
}

void GameStateManager::Draw(sf::RenderWindow& window)
{
  mStateStack.top()->Draw(window);
}

void GameStateManager::Push(State* pState)
{
  mStateStack.push(pState);
  mStateStack.top()->OnEnter();
}

void GameStateManager::Pop()
{
  mStateStack.top()->OnExit();
  delete mStateStack.top();
  mStateStack.pop();
}

void GameStateManager::Clear()
{
  while(!mStateStack.empty())
  {
    mStateStack.top()->OnExit();
    mStateStack.pop();
  }
}

void GameStateManager::ChangeState(State* pState)
{
  if(!mStateStack.empty())
  {
    if(mStateStack.top()->GetType() == pState->GetType())
    {
      return;
    }
    this->Pop();
  }
  this->Push(pState);
}



