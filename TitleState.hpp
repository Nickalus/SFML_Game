#ifndef TITLESCREEN_HPP
#define TITLESCREEN_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <iostream>
#include <array>

#include "State.hpp"
#include "SpriteNode.hpp"
#include "TextNode.hpp"

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
    bool ParseState();
    bool BuildState();
  private:
    enum Layer
    {
      Background,
      LayerCount
    };
  private:
    sf::Font mFont;
    sf::Sprite mBackground;

    bool mShowText, mChangingState;
    int mFade;
};

#endif
