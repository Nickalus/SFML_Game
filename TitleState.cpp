#include "TitleState.hpp"
#include "PlayState.hpp"
#include "GameStateManager.hpp"

TitleState::TitleState() : mShowText(true),
                           mChangingState(false),
                           mFade(255)
{
  this->SetType(TITLE);
}

TitleState::~TitleState()
{

}

bool TitleState::OnEnter()
{
  this->ParseState();
  this->BuildState();
}

bool TitleState::OnExit()
{
  return true;
}

void TitleState::ProcessEvents(const sf::Event& event)
{
  switch (event.type)
  {
    case sf::Event::KeyPressed:
      if(event.key.code == sf::Keyboard::P)
      {
        mChangingState = true;
      }
    break;
    default:
    break;
  }
}

void TitleState::Update(sf::Time dt)
{
  if(mChangingState)
  {
    mFade -= 5 * dt.asSeconds();
    mText.setColor(sf::Color(255, 255, 255, mFade));
    if(mFade <= 0)
    {
      GameStateManager::Instance()->Push(new PlayState);
    }
  }
}

void TitleState::Draw(sf::RenderWindow& window)
{
  window.draw(mText);
}

void TitleState::ChangeState(State* pState)
{
  for(int i = 255; i >= 0; i -= 5)
  {
    mText.setColor(sf::Color(255, 255, 255, i));
  }

  GameStateManager::Instance()->Push(new PlayState);
}

bool TitleState::ParseState()
{
  if(!mFont.loadFromFile("Data/Fonts/kenpixel_future_square.ttf"))
  {
    std::cout << "Could not load font" << std::endl;
    return false;
  }


  return true;
}

bool TitleState::BuildState()
{
  mText.setFont(mFont);
  mText.setString("Title Screen");
}
