#ifndef BOOK_WORLD_HPP
#define BOOK_WORLD_HPP

#include "SceneNode.hpp"
#include "SpriteNode.hpp"

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
    void LoadTextures();
    void BuildScene();

  private:
    enum Layer
    {
      Background,
      Play,
      Foreground,
      LayerCount
    };


  private:
    sf::RenderWindow & mWindow;
    sf::View mWorldView;
    TextureHolder mTextures;
    SceneNode mSceneGraph;
    std::array<SceneNode *, LayerCount> mSceneLayers;
    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    float mScrollSpeed;
};

#endif
