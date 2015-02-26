#ifndef TITLESCREEN_HPP
#define TITLESCREEN_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <iostream>

#include "State.hpp"

class TitleState : public State
{
  public:
    TitleState();
    ~TitleState();

    bool OnEnter();
    bool OnExit();

    void ProcessEvents(const sf::Event&);
    void Update(sf::Time);
    void Draw(sf::RenderWindow&);
  private:
    void ChangeState(State*);
    bool ParseState();
    bool BuildState();
  private:
    sf::Text mText;
    sf::Font mFont;
    sf::Sprite mBackgroundSprite;

    bool mShowText, mChangingState;
    int mFade;
};

#endif
