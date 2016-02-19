#include "World.hpp"
#include "TileNode.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow& window)
: mWindow(window)
, mWorldView(window.getDefaultView())
, mSceneGraph()
, mSceneLayers()
, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
, mScrollSpeed(-50.f)
, mPlayerCreature(nullptr)
, mBackground(new TileNode)
{
  LoadConfig();
  BuildScene();

  // Prepare the view
  mWorldView.setCenter(mSpawnPosition);
}

void World::Update(sf::Time dt)
{
  //Do game stuff
  //Move camera in the x-direction
  mWorldView.move(mScrollSpeed * dt.asSeconds(), 0.f);

  // Apply movements
  mSceneGraph.Update(dt);
}

void World::Draw()
{
  mWindow.setView(mWorldView);
  mWindow.draw(mSceneGraph);
}

void World::BuildScene()
{
  // Initialize the different layers
  for (std::size_t i = 0; i < LayerCount; ++i)
  {
    SceneNode::Ptr layer(new SceneNode());
    mSceneLayers[i] = layer.get();

    mSceneGraph.AttachChild(std::move(layer));
  }

  // Add the background to the scene
  background->setPosition(mWorldBounds.left, mWorldBounds.top);
  mSceneLayers[Background]->AttachChild(std::move(background));

  // Add player
  std::unique_ptr<Creature> leader(new Creature);
  mPlayerCreature = leader.get();
  mPlayerCreature->setPosition(mSpawnPosition);
  mPlayerCreature->SetVelocity(sf::Vector2f(40.f, mScrollSpeed));
  mSceneLayers[Foreground]->AttachChild(std::move(leader));
}

void World::LoadConfig()
{

}
