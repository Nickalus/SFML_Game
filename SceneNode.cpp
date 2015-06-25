#include "SceneNode.hpp"

#include <algorithm>
#include <cassert>


SceneNode::SceneNode() : mChildren(), mParent(nullptr)
{
}

void SceneNode::AttachChild(Ptr child)
{
  child->mParent = this;
  mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::DetachChild(const SceneNode& node)
{
  auto found = std::find_if(mChildren.begin(), mChildren.end(),
                            [&] (Ptr& p) { return p.get() == &node; });
    assert(found != mChildren.end());

      Ptr result = std::move(*found);
      result->mParent = nullptr;
      mChildren.erase(found);
      return result;
}

void SceneNode::Update(sf::Time dt)
{
  UpdateCurrent(dt);
  UpdateChildren(dt);
}

void SceneNode::UpdateCurrent(sf::Time)
{
  //Do nothing by default
}

void SceneNode::UpdateChildren(sf::Time dt)
{
  for(Ptr& child : mChildren)
    child->Update(dt);
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  //Apply transform of current node
  states.transform *= getTransform();

  //Draw node and children with changed transform
  DrawCurrent(target, states);
  DrawChildren(target, states);
}

void SceneNode::DrawCurrent(sf::RenderTarget&, sf::RenderStates) const
{
  //Do nothing by default
}

void SceneNode::DrawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
  for(const Ptr& child : mChildren)
    child->draw(target, states);
}

sf::Vector2f SceneNode::GetWorldPosition() const
{
  return GetWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::GetWorldTransform() const
{
  sf::Transform transform = sf::Transform::Identity;

  for (const SceneNode* node = this; node != nullptr; node = node->mParent)
    transform = node->getTransform() * transform;

  return transform;
}

