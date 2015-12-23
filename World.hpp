#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "SceneNode.hpp"

class World : private sf::NonCopyable
{
  public:
    explicit World(sf::RenderWindow &);

    void Update(sf::Time);
    void Draw(sf::RenderWindow &);
  private:
    enum Layer
    {
      Background,
      Air,
      LayerCount
    };
  private:
    sf::RenderWindow & mWindow;
    sf::View mView;
    SceneNode mSceneGraph;
    std::array<SceneNode*, LayerCount> mSceneLayers;

    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    float mScrollSpeed;
};

#endif
