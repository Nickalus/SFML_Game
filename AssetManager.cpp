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
  mTextureMap.LoadContent("Data/Images/Sprites", ".png");
}

const sf::Texture& AssetManager::GetTexture(int pos)
{
  return mTextureMap.Get(pos);
}
