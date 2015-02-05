#include "Game.hpp"

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Game"), 
               mIsPaused(false), 
               mTimePerFrame(sf::seconds(1.f / 60.f))
{
  //Create a new state machine
  mpGameStateMachine = new GameStateMachine();
}

void Game::Run()
{
  sf::Clock clock;
  
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  
  while(mWindow.isOpen())
  {
    ProcessEvents();
    timeSinceLastUpdate += clock.restart();
    while(timeSinceLastUpdate > mTimePerFrame)
    {
      timeSinceLastUpdate -= mTimePerFrame;
      processEvents();
      Update(mTimePerFrame);
    }
    Draw();
}

void Game::ProcessEvents()
{
  sf::Event event;
  while(mWindow.pollEvent(event))
  {
    mpGameStateMachine.ProcessEvents(event);
    
    switch(event.type())
    {
      case sf::Event::Closed:
        mWindow.close();
      break;
    }
  }
}

void Game::Update(sf::Time deltaTime)
{
  mpGameStateMachine.Update(deltaTime)
}

void Game::Draw()
{
  mWindow.clear();
  mpGameStateMachine.Draw();
  mWindow.display();
}
