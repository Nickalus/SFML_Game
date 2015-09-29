#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>
#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include <SFML/Graphics.hpp>

namespace bfs = boost::filesystem;

template<typename Asset>
class AssetMap
{
  public:
    AssetMap();

    void LoadContent(const std::string&, const std::string&);

    //Getter operations
    Asset& Get(int);
    const Asset& Get(int) const;
  private: //Member functions
    void AddContent(const std::string&, int);
  private:
    std::map<int, std::unique_ptr<Asset>> mMap;
};

template <class Asset>
AssetMap<Asset>::AssetMap()
{
}

template <class Asset>
void AssetMap<Asset>::LoadContent(const std::string& path, const std::string& ext)
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
        AddContent(iterator->path().string(), mMap.size());
      }
    }
  }
  else
  {
    std::cout << path << " Does not exist!" << std::endl;
  }
}

template <class Asset>
void AssetMap<Asset>::AddContent(const std::string& file, int ID)
{
  //Create and load resource
  std::unique_ptr<Asset> tempAsset(new Asset());

  if(!tempAsset->loadFromFile(file))
    throw std::runtime_error("Failed to load " + file);

  //Insert
  mMap[ID] = std::move(tempAsset);
}

template <class Asset>
Asset& AssetMap<Asset>::Get(int pos)
{
  return *mMap[pos];
}
