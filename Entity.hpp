#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/System/Vector2.hpp>

#include "SceneNode.hpp"

class Entity : public SceneNode
{
  public:
    void SetVelocity(sf::Vector2f);
    sf::Vector2f GetVelocity() const;

  private:
    virtual void UpdateCurrent(sf::Time);
    
  private:
    sf::Vector2f mVelocity;
};

#endif
