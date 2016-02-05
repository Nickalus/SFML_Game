#include "World.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow& window)
: mWindow(window)
, mWorldView(window.getDefaultView())
, mTextures()
, mSceneGraph()
, mSceneLayers()
, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
, mScrollSpeed(-50.f)
, mPlayerAircraft(nullptr)
{
  LoadConfig();
  loadTextures();
  buildScene();

  // Prepare the view
  mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
  //Do game stuff

  // Apply movements
  mSceneGraph.update(dt);
}

void World::draw()
{
  mWindow.setView(mWorldView);
  mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{
  mTextures.load(Textures::Eagle, "Media/Textures/Eagle.png");
  mTextures.load(Textures::Raptor, "Media/Textures/Raptor.png");
  mTextures.load(Textures::Desert, "Media/Textures/Desert.png");
}

void World::buildScene()
{
  // Initialize the different layers
  for (std::size_t i = 0; i < LayerCount; ++i)
  {
    SceneNode::Ptr layer(new SceneNode());
    mSceneLayers[i] = layer.get();

    mSceneGraph.attachChild(std::move(layer));
  }

  // Prepare the tiled background
  sf::Texture& texture = mTextures.get(Textures::Desert);
  sf::IntRect textureRect(mWorldBounds);
  texture.setRepeated(true);

  // Add the background sprite to the scene
  std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
  backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
  mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

  // Add player
  std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Eagle, mTextures));
  mPlayerAircraft = leader.get();
  mPlayerAircraft->setPosition(mSpawnPosition);
  mPlayerAircraft->setVelocity(40.f, mScrollSpeed);
  mSceneLayers[Air]->attachChild(std::move(leader));
}
