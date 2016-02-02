#include "Entity.hpp"

void Entity::SetVelocity(sf::Vector2f velocity)
{
  mVelocity = velocity;
}

sf::Vector2f Entity::GetVelocity() const
{
  return mVelocity;
}

void Entity::UpdateCurrent(sf::Time dt)
{
  move(mVelocity * dt.asSeconds());
}
