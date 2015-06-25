#ifndef SPRITENODE_H
#define SPRITENODE_H

#include "SceneNode.hpp"

class SpriteNode : public SceneNode
{
  public:
    SpriteNode(const sf::Texture&);
    ~SpriteNode();
  private:
    virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
  private:
    sf::Sprite mSprite;
};

#endif // SPRITENODE_H
