#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity
{
  public:
    void SetVelocity(sf::Vector2f);
    sf::Vector2f GetVelocity() const;
  private:
    sf::Vector2f mVelocity;
  protected:
};

#endif
