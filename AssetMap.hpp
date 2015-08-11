#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include <SFML/Graphics.hpp>

namespace bfs = boost::filesystem;

template<typename T>
class AssetMap
{
  public:
    AssetMap();

    void LoadContent(const std::string&, const std::string&);

    //Overload the subscript operator
    T& operator[](int position);
  private: //Member functions
    void AddContent(boost::filesystem::path);
  private:
    std::map<int, sf::Texture*> mMap;
};

template <class T>
AssetMap<T>::AssetMap()
{
}

template <class T>
T& AssetMap<T>::operator[](int position)
{
  return *mMap[position];
}

template <class T>
void AssetMap<T>::LoadContent(const std::string& path, const std::string& ext)
{
  //Create the path with boost filesystem
  bfs::path directory(path);

  //Check to see if the directory exists
  if(bfs::exists(path))
  {
    //create the iterators
    bfs::directory_iterator iterator(directory), end;

    //Loop through all files
    for(; iterator != end; ++iterator)
    {
      //Check the extension of the file
      if(iterator->path().extension() == ext)
      {
        //add to map
        AddContent(iterator->path());      }
    }
  }
  else
  {
    std::cout << path << " Does not exist!" << std::endl;
  }
}

template <class T>
void AssetMap<T>::AddContent(bfs::path file)
{
  //Create and load resource
  sf::Texture* tempTexture = new sf::Texture();

  if(!tempTexture->loadFromFile(file.string()))
    throw std::runtime_error("Failed to load " + file.string());

  //std::string srtID = file.stem().string();

  int id = std::atoi(file.stem().string().c_str());

  //Insert and check success

  mMap[id] = tempTexture;
  std::cout << "I crashed!" << std::endl;
  //assert(inserted.second);
}
