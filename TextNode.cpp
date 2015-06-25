#include "TextNode.hpp"

TextNode::TextNode(const std::string& text, int font, int size)
{
  mText.setFont(AssetManager::Instance()->GetFont(font));
  mText.setCharacterSize(size);

  mText.setString(text);
}

TextNode::~TextNode()
{

}

void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(mText, states);
}
