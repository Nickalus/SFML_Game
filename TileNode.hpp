#ifndef TILENODE_HPP
#define TILENODE_HPP

#include "SceneNode.hpp"

class TileNode : public SceneNode
{
  public:
    explicit TileNode();

  private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

  private:
    sf::Sprite mSprite;
};

#endif
