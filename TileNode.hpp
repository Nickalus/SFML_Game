#ifndef TILENODE_HPP
#define TILENODE_HPP

#include "SceneNode.hpp"

class TileNode : public SceneNode
{
  public:
    TileNode();
    explicit TileNode(sf::Vector2i);

    void SetTileIDs(const std::vector<std::vector<int>> &);

  private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

  private:
    sf::Sprite mSprite;
    sf::Vector2i mTileSize;
    std::vector<std::vector<int>> mTileIDs;
};

#endif
