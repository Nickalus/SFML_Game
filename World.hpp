#ifndef BOOK_WORLD_HPP
#define BOOK_WORLD_HPP

#include "SceneNode.hpp"
#include "SpriteNode.hpp"
#include "TileNode.hpp"
#include "Creature.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>

class World : private sf::NonCopyable
{
  public:
    explicit  World(sf::RenderWindow &);
    ~World();

    void Update(sf::Time);
    void Draw();

  private:
    void LoadConfig();
    void BuildScene();

  private:
    enum Layer
    {
      Background,
      Foreground,
      LayerCount
    };

  private:
    sf::RenderWindow & mWindow;
    sf::View mWorldView;
    SceneNode mSceneGraph;
    std::array<SceneNode *, LayerCount> mSceneLayers;
    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    float mScrollSpeed;
    Creature * mPlayerCreature;

    //Layers
    std::unique_ptr<TileNode> mBackground;
};

#endif
