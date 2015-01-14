#include "Game.hpp"

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application"), 
               mPlayer(), mTexture(), 
               mTimePerFrame(sf::seconds(1.f / 60.f))
{
  if(!mTexture.loadFromFile("Data/Images/Eagle.png"))
  {
    // Handle loading error
  }
  
  mPlayer.setTexture(mTexture);
  mPlayer.setPosition(100.f, 100.f);
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
    mPlayer.ProcessEvents(event);
    
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
  sf::Vector2f movement(0.f, 0.f);
  
  if(mIsMovingUp)
  {
    movement.y -= PlayerSpeed;
  }
  if(mIsMovingDown)
  {
    movement.y += PlayerSpeed;
  }
  if(mIsMovingLeft)
  {
    movement.x -= PlayerSpeed;
  }
  if(mIsMovingRight)
  {
    movement.x += PlayerSpeed;
  }
    
  mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::Draw()
{
  mWindow.clear();
  mWindow.draw(mPlayer);
  mWindow.display();
}
