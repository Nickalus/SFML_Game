#include "Game.hpp"

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Game"),
               mIsPaused(false),
               mTimePerFrame(sf::seconds(1.f / 60.f))
{
}

void Game::Run()
{
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while(mWindow.isOpen())
  {
    timeSinceLastUpdate += clock.restart();

    while(timeSinceLastUpdate > mTimePerFrame)
    {
      timeSinceLastUpdate -= mTimePerFrame;
      this->ProcessEvents();
      this->Update(mTimePerFrame);
    }

    this->Draw(mWindow);
  }
}

void Game::ProcessEvents()
{
  sf::Event event;
  while(mWindow.pollEvent(event))
  {
    switch(event.type)
    {
      case sf::Event::Closed:
        mWindow.close();
      break;
      default:
      break;
    }
  }
}

void Game::Update(sf::Time deltaTime)
{
  mStateMachine.Update(deltaTime);
}

void Game::Draw(sf::RenderWindow& window)
{
  mWindow.clear();
  mStateMachine.Draw(window);
  mWindow.display();
}
