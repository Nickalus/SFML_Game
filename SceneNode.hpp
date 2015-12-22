#ifndef SCENENODE_HPP
#define SCENENODE_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>


class SceneNode : public sf::Transformable, 
                  public sf::Drawable, 
                  private sf::NonCopyable
{
  public:
    typedef std::unique_ptr<SceneNode> Ptr;

  public:
    SceneNode();

    void AttachChild(Ptr);
    Ptr DetachChild(const SceneNode&);

    void Update(sf::Time);

    sf::Vector2f GetWorldPosition() const;
    sf::Transform GetWorldTransform() const;

  private:
    virtual void UpdateCurrent(sf::Time);
    void UpdateChildren(sf::Time);

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    virtual void DrawCurrent(sf::RenderTarget&, sf::RenderStates) const;
    void DrawChildren(sf::RenderTarget&, sf::RenderStates) const;

  private:
    std::vector<Ptr> mChildren;
    SceneNode * mParent;
};

#endif
