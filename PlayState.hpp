#ifndef PLAYSCREEN_HPP
#define PLAYSCREEN_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <iostream>

#include "State.hpp"

class PlayState : public State
{
  public:
    PlayState();
    ~PlayState();

    bool OnEnter();
    bool OnExit();

    void ProcessEvents(const sf::Event&);
    void Update(sf::Time);
    void Draw(sf::RenderWindow&);
  private:
    bool ParseState();
  private:
    sf::Text mText;
    sf::Font mFont;
    sf::Sprite mBackgroundSprite;

    bool mShowText;
};

#endif
