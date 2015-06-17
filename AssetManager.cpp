#include "AssetManager.hpp"

AssetManager* AssetManager::mInstance = nullptr;

AssetManager* AssetManager::Instance()
{
  if(mInstance != nullptr)
  {
    mInstance = new AssetManager;
  }

  return mInstance;
}

void AssetManager::LoadContent()
{
  /*
   TODO: Create a better way to do this without tryping so much code...
  */
  mTextureMap.LoadContent("Data/Images/Sprites");
}

sf::Texture& GetTexture(int pos)
{
  return mTextureMap[pos];
}
