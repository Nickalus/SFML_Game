#include "Player.hpp"

void Player::Player(int speed) : mPlayerSpeed(speed)
{
}

void Player::Player(sf::Vector2f position, int speed) 
: mPosition(position), 
  mPlayerSpeed(speed)
{
}

void Player::ProcessEvents(const sf::Event& e)
{
  switch(event.type())
  {
    case sf::Event::KeyPressed:
      HandleInput(event.key.code, true);
    break;
    case sf::Event::KeyReleased:
      HandleInput(event.key.code, false);
    break;
  }
}

void Player::Update(sf::Time dt)
{
  sf::Vector2f movement(0.f, 0.f);
  
  if(mIsMovingUp)
    movement.y -= mPlayerSpeed;
  if(mIsMovingDown)
    movement.y += mPlayerSpeed;
  if(mIsMovingLeft)
    movement.x -= mPlayerSpeed;
  if(mIsMovingRight)
    movement.x += mPlayerSpeed;
    
    mPlayer.move(movement * dt.asSeconds());
}

void Player::HandleInput(sf::Keyboard::Key key, bool isPressed)
{
  if(key == sf::Keyboard::W)
  {
    mIsMovingUp = isPressed;
  }
  else if(key == sf::Keyboard::S)
  {
    mIsMovingDown = isPressed;
  }
  else if(key == sf::Keyboard::A)
  {
    mIsMovingLeft = isPressed;
  }
  else if(key == sf::Keyboard::D)
  {
    mIsMovingRight = isPressed;
  }
}
