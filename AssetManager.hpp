#ifndef ASSETMANAGER_HPP
#define ASSETMANAGER_HPP

//SFML
#include <SFML/Graphics.hpp>
//STL
#include <map>
#include <memory>
//Custom
#include "AssetMap.hpp"

class AssetManager
{
  public:
    //Used to access member functions
    static AssetManager* Instance();

    //Load all assets
    void LoadContent();

    //Getter functions
    sf::Texture& GetTexture(int);
    sf::Font& GetFont(int);
  private:
  private:
    AssetMap<sf::Texture> mTextureMap;
    AssetMap<sf::Font> mFontMap;

    static AssetManager* mInstance;
};

#endif
