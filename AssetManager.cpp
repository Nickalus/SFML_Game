#include "AssetManager.hpp"

AssetManager& AssetManager::Instance()
{
  static AssetManager mInstance;

  return mInstance;
}

void AssetManager::LoadContent()
{
  mTextureMap.LoadContent("/home/nick/Projects/SFML_Game/build/Data/Sprites", ".png");
}

sf::Texture& AssetManager::GetTexture(int pos)
{
  return mTextureMap[pos];
}
