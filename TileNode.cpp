#include "TileNode.hpp"

#include <SFML/Graphics/RenderTarget.hpp>


TileNode::TileNode()
{
}

void TileNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(mSprite, states);
}
