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
  switch(event.type)
  {
    case sf::Event::KeyReleased:
    case sf::Event::MouseButtonReleased:
      mChangingState = true;
    break;
    default:
    break;
  }
}

void TitleState::Update(sf::Time dt)
{
  if(mChangingState)
  {
    mFade -= 10 * dt.asSeconds();
    //mText.setColor(sf::Color(255, 255, 255, mFade));
    if(mFade <= 0)
    {
      GameStateManager::Instance()->ChangeState(new PlayState);
    }
  }
  this->mSceneGraph.Update(dt);
}

void TitleState::Draw(sf::RenderWindow& window)
{
  window.draw(mSceneGraph);
}

bool TitleState::ParseState()
{
  return true;
}

bool TitleState::BuildState()
{
  //Add text to scene
  if(!mFont.loadFromFile("Data/Fonts/kenpixel_future_square.ttf"))
  {
    std::cout << "Could not load font" << std::endl;
    return false;
  }
  sf::Text mText;
  mText.setFont(mFont);
  mText.setColor(sf::Color::Red);
  mText.setString("Title Screen");

  //Add the background sprite to the scene
  sf::Texture BgTexture;
  if(!BgTexture.loadFromFile("Data/Backgrounds/BG.png"))
  {
    std::cout << "Could not load background" << std::endl;
    return false;
  }
}
