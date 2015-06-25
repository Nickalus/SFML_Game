#ifndef TEXTNODE_HPP
#define TEXTNODE_HPP

#include "SceneNode.hpp"
#include "AssetManager.hpp"

#include <string>

class TextNode : public SceneNode
{
  public:
    TextNode(const std::string&, int, int);
    ~TextNode();
  private:
    virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
  private:
    sf::Text mText;
};

#endif
