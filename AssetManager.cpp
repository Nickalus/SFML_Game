#include "AssetManager.hpp"

AssetManager& AssetManager::Instance()
{
  static AssetManager mInstance;

  return mInstance;
}

void AssetManager::LoadContent()
{
  mTextureMap.LoadContent("/data/sprites", ".png");
}

sf::Texture& AssetManager::GetTexture(int pos)
{
  return mTextureMap[pos];
}
