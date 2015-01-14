#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player
{
  public:
    Player(int);
    Player(sf::Vector2f);
    
    void ProcessEvents(const sf::Event&);
    void Update(sf::Time);
    void Draw(sf::RenderWindow);
  private:
    void HandleInput(sf::Keyboard::Key, bool);
  private:
    sf::Vector2f mPosition;
    float mPlayerSpeed;
};

#endif
