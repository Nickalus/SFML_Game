#include "PlayState.hpp"

PlayState::PlayState() : mShowText(true)
{
  this->SetType(TITLE);
}

PlayState::~PlayState()
{

}

bool PlayState::OnEnter()
{
  if(!mFont.loadFromFile("Data/Fonts/kenpixel_future_square.ttf"))
  {
    std::cout << "Could not load font" << std::endl;
    return false;
  }

  mText.setFont(mFont);
  mText.setString("Play Screen");
  return true;
}

bool PlayState::OnExit()
{
  return true;
}

void PlayState::ProcessEvents(const sf::Event& event)
{
  switch (event.type)
  {
    case sf::Event::KeyPressed:

    break;
    case sf::Event::KeyReleased:
    break;
    default:
    break;
  }
}

void PlayState::Update(sf::Time dt)
{

}

void PlayState::Draw(sf::RenderWindow& window)
{
  window.draw(mText);
}

bool PlayState::ParseState()
{

}
